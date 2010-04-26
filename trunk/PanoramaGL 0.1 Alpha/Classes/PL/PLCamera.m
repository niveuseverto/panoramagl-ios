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

#import "PLCamera.h"

@interface  PLCamera()

- (void)initializeValues;

@end


@implementation PLCamera

@synthesize isFovEnabled;
@synthesize fov, fovSensitivity;
@synthesize fovFactor;
@synthesize fovRange, fovFactorRange;

#pragma mark -
#pragma mark init methods

+ (id)camera
{
	return [[PLCamera alloc] init];
}

- (void)initializeValues
{
	fovRange = PLRangeMake(kDefaultFovMinValue, kDefaultFovMaxValue);
	isFovEnabled = YES;
	fovSensitivity = kDefaultFovSensitivity;
	fovFactorRange = PLRangeMake(kDefaultFovFactorMinValue, kDefaultFovFactorMaxValue);
	[super initializeValues];
}

- (void)reset
{
	self.fov = fovRange.min + ([PLMath distanceBetweenPoints:CGPointMake(fovRange.min, 0.0f) :CGPointMake(fovRange.max, 0.0f)] / 2.0f); 
	[super reset];
}

#pragma mark -
#pragma mark fov methods

- (void)setFov:(float)value
{
	if(isFovEnabled)
	{
		fov = [PLMath normalizeFov:value range:fovRange];
		if(fov <= fovRange.min)
			fovFactor = fovFactorRange.min;
		else if(fov >= fovRange.max)
			fovFactor = fovFactorRange.max;
		else 
		{
			if(fov < 0.0f)
				fovFactor = kFovFactorOffsetValue - ((kFovFactorOffsetValue - fovFactorRange.min) / (fovRange.min/fov));
			else
				fovFactor = ABS((fov * (fovFactorRange.max - kFovFactorOffsetValue)) / fovRange.max) + kFovFactorOffsetValue;
		}
	}
}

- (void)addFovWithDistance:(float)distance;
{
	self.fov += (distance / fovSensitivity);
}

- (void)addFovWithStartPoint:(CGPoint)startPoint endPoint:(CGPoint)endPoint sign:(int)sign
{
	[self addFovWithDistance: [PLMath distanceBetweenPoints:startPoint :endPoint] * (sign < 0 ? -1 : 1)];
}

#pragma mark -
#pragma mark utility methods

- (void)cloneCameraProperties:(PLCamera *)value
{
	isFovEnabled = value.isFovEnabled;
	fovRange = value.fovRange;
	fovFactorRange = value.fovFactorRange;
	self.fov = value.fov;
	[super clonePropertiesOf:(PLObject *)value];
}

@end
