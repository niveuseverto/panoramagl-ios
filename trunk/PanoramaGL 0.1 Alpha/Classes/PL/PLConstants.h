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

#pragma mark -
#pragma mark utility consts

#define kFloatMinValue FLT_MIN
#define kFloatMaxValue FLT_MAX

#pragma mark -
#pragma mark buffer consts

#define kUseDepthBuffer 0

#pragma mark -
#pragma mark texture consts

#define kTextureMaxWidth	1024
#define kTextureMaxHeight	1024

#pragma mark -
#pragma mark cube consts

#define kCubeFrontFaceIndex		0
#define kCubeBackFaceIndex		1
#define kCubeLeftFaceIndex		2
#define kCubeRightFaceIndex		3
#define kCubeTopFaceIndex		4
#define kCubeBottomFaceIndex	5

#pragma mark -
#pragma mark sphere consts

#define kDefaultSphereDivs 30

#pragma mark -
#pragma mark cylinder consts

#define kDefaultCylinderDivs		60
#define kDefaultCylinderHeight		3.0f
#define kDefaultCylinderHeightCalc	YES

#pragma mark -
#pragma mark rotation consts

#define kDefaultRotateSensitivity		30.0f
#define kDefaultAnimationTimerInterval	1.0/45.0

#define kDefaultRotateMinRange -180.0f
#define kDefaultRotateMaxRange  180.0f

#pragma mark -
#pragma mark fov (field of view) consts

#define kDefaultFovSensitivity 70.0f

#define kDefaultFovMinValue -180.0f
#define kDefaultFovMaxValue  180.0f

#define kDefaultFovFactorMinValue 0.7f
#define kDefaultFovFactorMaxValue 1.18f

#define kDefaultCylinderFovFactorMinValue 0.0f
#define kDefaultCylinderFovFactorMaxValue 1.18f

#define kFovFactorOffsetValue 1.0f

#pragma mark -
#pragma mark inertia consts

#define kDefaultInertiaInterval 3

#pragma mark -
#pragma mark accelerometer consts

#define kDefaultAccelerometerSensitivity	5.0f
#define kDefaultAccelerometerInterval		1.0/45.0
#define kAccelerometerSensitivityMinValue	1.0f
#define kAccelerometerSensitivityMaxValue	10.0f
#define kAccelerometerMultiplyFactor		100.0f

#pragma mark -
#pragma mark scrolling consts

#define kDefaultMinDistanceToEnableScrolling 50