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

#import <UIKit/UIImage.h>
#import <Foundation/NSData.h>

@interface PLImage : NSObject
{
	/**member variables*/
@private
	CGImageRef cgImage;
	NSUInteger width, height;
	BOOL isRecycled;
}

/**properties*/

@property(nonatomic, readonly, getter=getWidth) NSUInteger width;
@property(nonatomic, readonly, getter=getHeight) NSUInteger height;

@property(nonatomic, readonly, getter=getCGImage) CGImageRef CGImage;

@property(nonatomic, readonly, getter=getCount) NSUInteger count;
@property(nonatomic, readonly, getter=getBits) unsigned char * bits;

@property(nonatomic, readonly, getter=isRecycled) BOOL isRecycled;

/**init methods*/

-(id)initWithCGImage:(CGImageRef)image;
-(id)initWithSize:(CGSize)size;
-(id)initWithDimensions:(NSUInteger)width :(NSUInteger)height;
-(id)initWithPath:(NSString *)path;
-(id)initWithBuffer:(NSData *)buffer;

/**image methods*/

+(id)imageWithSizeZero;
+(id)imageWithCGImage:(CGImageRef)image;
+(id)imageWithSize:(CGSize)size;
+(id)imageWithDimensions:(NSUInteger)width :(NSUInteger)height;
+(id)imageWithPath:(NSString *)path;
+(id)imageWithBuffer:(NSData *)buffer;

-(NSUInteger)getWidth;
-(NSUInteger)getHeight;
-(CGSize)getSize;
-(CGRect)getRect;

-(CGImageRef)getCGImage;

-(NSUInteger)getCount;
-(unsigned char *)getBits;

-(BOOL)isValid;
-(BOOL)equals:(PLImage *)image;
-(PLImage *)assign:(PLImage *)image;

-(PLImage *)clone;
-(CGImageRef)cloneCGImage;

-(PLImage *)crop:(CGRect)rect;

-(PLImage *)scale:(CGSize)size;

-(PLImage *)rotate:(NSInteger)angle;

-(PLImage *)mirrorHorizontally;
-(PLImage *)mirrorVertically;
-(PLImage *)mirror:(BOOL)horizontally :(BOOL)vertically;

-(BOOL)save:(NSString *)path;
-(BOOL)save:(NSString *)path quality:(NSUInteger)quality;

-(PLImage *)getSubImageWithRect:(CGRect)rect;

-(BOOL)isRecycled;
-(void)recycle;

+(PLImage *)joinImagesHorizontally:(PLImage *)leftImage rightImage:(PLImage *)rightImage;

@end