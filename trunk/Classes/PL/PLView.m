/*
 * This file is part of the PanoramaGL library.
 *
 *  Author: Javier Baez <javbaezga@gmail.com>
 *
 *  $Id$
 *
 * This is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; version 3 of
 * the License
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this software; if not, write to the Free
 * Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA, or see the FSF site: http://www.fsf.org.
 */

#import "PLView.h"

@interface PLView ()

- (void)initializeValues;

@end

@implementation PLView

@synthesize type;
@synthesize camera;

#pragma mark -
#pragma mark init methods

- (void)allocAndInitVariables
{
	[super allocAndInitVariables];
	scene = [PLScene scene];
	renderer = [PLRenderer rendererWithView:self scene:[scene retain]];
	camera = [PLCamera camera];
}

- (void)initializeValues
{
	[super initializeValues];
	textures = [[NSMutableArray array] retain];
	type = PLViewTypeUnknown;
}

- (void)reset
{
	if(camera)
		[camera reset];
	[super reset];
}

#pragma mark -
#pragma mark property methods

- (void)setType:(PLViewType)value
{
	type = value;
	if(sceneElement)
		[sceneElement release];
	
	switch (value) {
		case PLViewTypeCylindrical:
			camera.fovFactorRange = PLRangeMake(kDefaultCylinderFovFactorMinValue, kDefaultCylinderFovFactorMaxValue);
			sceneElement = [PLCylinder cylinder];
			break;
		case PLViewTypeSpherical:
			camera.fovFactorRange = PLRangeMake(kDefaultFovFactorMinValue, kDefaultFovFactorMaxValue);
			sceneElement = [PLSphere sphere];
			break;
		case PLViewTypeCubeFaces:
			camera.fovFactorRange = PLRangeMake(kDefaultFovFactorMinValue, kDefaultFovFactorMaxValue);
			sceneElement = [PLCube cube];
			break;
		case PLViewTypeUnknown:
			sceneElement = nil;
			break;
		default:
			[NSException raise:@"Invalid panorama type" format:@"Type unknown", nil];
			break;
	}
	
	if(sceneElement)
	{
		sceneElement = [sceneElement retain];
		for(PLTexture * texture in textures)
			[sceneElement addTexture:texture];
		[scene addElement:sceneElement];
	}
}

#pragma mark -
#pragma mark draw methods

- (void)drawView 
{    
	[super drawView];

	[sceneElement clonePropertiesOf:camera];
	[scene.currentCamera cloneCameraProperties:camera];
	scene.currentCamera.rotation = PLRotationMake(0.0f, 0.0f, 0.0f);
	scene.currentCamera.position = PLPositionMake(0.0f, 0.0f, 0.0f);
	
	if(!isValidForFov && !isValidForOrientation)
		[sceneElement rotateWithStartPoint:startPoint endPoint:endPoint sensitivity:camera.rotateSensitivity];
	[renderer render];

	camera.rotation = PLRotationMake(sceneElement.pitch, sceneElement.yaw, sceneElement.roll);	
}

#pragma mark -
#pragma mark fov methods

- (BOOL)calculateFov:(NSSet *)touches
{
	if([super calculateFov:touches])
	{
		[camera addFovWithDistance:fovDistance];
		[scene.currentCamera addFovWithDistance:fovDistance];
		return YES;
	}
	return NO;
}

#pragma mark -
#pragma mark texture methods

- (void)addTexture:(PLTexture *)texture
{
	[textures addObject:texture];
	if(sceneElement)
		[sceneElement addTexture:texture];
}
				
- (void)removeTexture:(PLTexture *)texture
{
	[textures removeObject:texture];
	if(sceneElement)
		[sceneElement removeTexture:texture];
}
				
- (void)removeTextureAtIndex:(NSUInteger) index
{
	[textures removeObjectAtIndex:index];
	if(sceneElement)
		[sceneElement removeTextureAtIndex:index];
}
				
- (void)removeAllTextures
{
	[textures removeAllObjects];
	if(sceneElement)
		[sceneElement removeAllTextures];
}

#pragma mark -
#pragma mark orientation methods

- (void)orientationChanged:(UIDeviceOrientation)orientation
{
	if(camera && sceneElement)
	{
		camera.orientation = orientation;
		sceneElement.orientation = orientation;
		camera.pitchRange = sceneElement.pitchRange;
		camera.yawRange = sceneElement.yawRange;
		camera.rollRange = sceneElement.rollRange;
		camera.rotation = PLRotationMake(sceneElement.pitch, sceneElement.yaw, sceneElement.roll);
	}
}

#pragma mark -
#pragma mark dealloc methods

- (void)dealloc 
{    
	if(textures)
		[textures release];
	if(camera)
		[camera release];
	if(sceneElement)
		[sceneElement release];
	if(scene)
		[scene release];
    if(renderer)
		[renderer release];
	[super dealloc];
}
				
@end
