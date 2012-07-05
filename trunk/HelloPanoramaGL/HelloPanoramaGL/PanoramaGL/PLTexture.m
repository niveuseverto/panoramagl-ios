/*
 * PanoramaGL library
 * Version 0.1
 * Copyright (c) 2010 Javier Baez <javbaezga@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import "PLObjectBaseProtected.h"
#import "PLTexture.h"

/**static varieables*/

@interface PLTexture(Private)

-(int)convertToValidValueForDimension:(int)dimension;
-(BOOL)loadTextureWithObject;
-(void)releaseImage;
-(void)deleteTexture;

@end

@implementation PLTexture

@synthesize delegate;

/**init methods*/

-(id)initWithImage:(PLImage *)imageValue
{
	if(self = [super init])
	{
		isValid = FALSE;
		image = (imageValue ? [imageValue retain] : nil);
	}
	return self;
}

-(void)initializeValues
{
	[super initializeValues];
	isRecycled = TRUE;
	textureID = (GLuint *)malloc(sizeof(GLuint));
	textureID[0] = 0;
	isValid = FALSE;
	format = PLTextureColorFormatRGBA8888;
	image = nil;
}

+(id)textureWithImage:(PLImage *)image
{
	return [[[PLTexture alloc] initWithImage:image] autorelease];
}

/**property methods*/

-(GLuint)getTextureID
{
	if(!isValid)
	{
		@try
		{
			[self loadTextureWithObject];
		}
		@catch(NSException *e)
		{
			[PLLog error:@"PLTexture::getTextureId" format:@"getTextureId: %@", e.reason];
		}
	}
	return textureID[0];
}
			 
-(int)getWidth
{
	return width;
}
			 
-(int)getHeight
{
	return height;
}
			 
-(BOOL)isValid
{
	return isValid;
}
			 
-(BOOL)isRecycled
{
	return isRecycled;
}
			 
-(PLTextureColorFormat)getFormat
{
	return format;
}
			 
-(void)setFormat:(PLTextureColorFormat)value
{
	format = value;
}
			 
/**util methods*/
			 
-(int)convertToValidValueForDimension:(int)dimension
{
	if(dimension <= 4)
		return 4;
	else if(dimension <= 8)
		return 8;
	else if(dimension <= 16)
		return 16;
	else if(dimension <= 32)
		return 32;
	else if(dimension <= 64)
		return 64;
	else if(dimension <= 128)
		return 128;
	else if(dimension <= 256)
		return 256;
	else if(dimension <= 512)
		return 512;
	else
		return 1024;
}

/**load methods*/
			 
-(BOOL)loadTextureWithObject
{
	@try
	{
		if(image == nil || ![image isValid])
			return FALSE;
					 
		[self deleteTexture];
					 
		width = [image getWidth];
		height = [image getHeight];
					 
		if(width > kTextureMaxWidth || height > kTextureMaxHeight)
		{
			[PLLog error:@"PLNativeTexture::loadTextureWithObject"
				  format:@"Invalid texture size. Texture max size is %d x %d, currently is (%d x %d)", 
						kTextureMaxWidth, kTextureMaxHeight, width, height];
			[self releaseImage];
			return FALSE;
		}
					 
		BOOL isResizableImage = FALSE;
		if(![PLMath isPowerOfTwo:width] || width > kTextureMaxWidth)
		{
			isResizableImage = TRUE;
			width = [self convertToValidValueForDimension:width];
		}
		if(![PLMath isPowerOfTwo:height] || height > kTextureMaxHeight)
		{
			isResizableImage = TRUE;
			height = [self convertToValidValueForDimension:height];
		}
					 
		if(isResizableImage)
			[image scale:CGSizeMake(width, height)];
					 
		glGenTextures(1, &textureID[0]);
					 
		int errGL = glGetError();
		if(errGL != GL_NO_ERROR)
		{
			[PLLog error:@"PLNativeTexture::loadTextureWithObject"
				  format:@"glGetError #1 = (%d) %s ...", 
						errGL, (const char *)gluErrorString(errGL)];
			[self releaseImage];
			return FALSE;
		}
					 
		glBindTexture(GL_TEXTURE_2D, textureID[0]);
		errGL = glGetError();
		if(errGL != GL_NO_ERROR)
		{
			[PLLog error:@"PLNativeTexture::loadTextureWithObject"
				  format:@"glGetError #2 = (%d) %s ...", 
						errGL, (const char *)gluErrorString(errGL)];
			[self releaseImage];
			return FALSE;
		}

		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //GLES10.GL_NEAREST
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); //GL10.GL_REPEAT
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
					 
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); //GL10.GL_REPLACE
					 
		unsigned char * bits = image.bits;
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width , height, 0, GL_RGBA, GL_UNSIGNED_BYTE, bits);
					 
		free(bits);
		bits = nil;
						  
		errGL = glGetError();
		if(errGL != GL_NO_ERROR)
		{
			[PLLog error:@"PLNativeTexture::loadTextureWithObject" 
				  format:@"glGetError #3 = (%d) %s ...", 
						errGL, (const char *)gluErrorString(errGL)];
			[self releaseImage];
			return FALSE;
		}
					 
		[self releaseImage];
					 
		isValid = TRUE;
		isRecycled = FALSE;
					 
		if(delegate)
			[delegate didLoad:self];
					 
		return TRUE;
	}
	@catch(NSException *e)
	{
		[PLLog error:@"PLNativeTexture::loadTextureWithObject" format:@"Error: %@", e.reason];
	}
	return FALSE;
}

/**delete methods*/
			 
-(void)deleteTexture
{
	if(textureID && textureID[0] != 0)
	{
		glDeleteTextures(1, &textureID[0]);
		textureID[0] = 0;
	}
	isValid = FALSE;
}
			 
/**recycle methods*/
			 
-(void)recycle
{
	if(!isRecycled)
	{
		[self releaseImage];
		[self deleteTexture];
		isRecycled = TRUE;
	}
}
			 
/**dealloc methods*/
			 
-(void)releaseImage
{
	if(image)
	{
		[image recycle];
		[image release];
		image = nil;
	}
}
			 
-(void)dealloc
{
	[self recycle];
	delegate = nil;
	if(textureID)
	{
		free(textureID);
		textureID = nil;
	}
	[super dealloc];
}
			 
@end