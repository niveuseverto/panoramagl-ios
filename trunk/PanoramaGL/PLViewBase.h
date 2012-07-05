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

#import <UIKit/UIKit.h>
#import <OpenGLES/EAGL.h>
#import <OpenGLES/EAGLDrawable.h>
#import <QuartzCore/QuartzCore.h>
#import <CoreMotion/CoreMotion.h>
#import <CoreLocation/CoreLocation.h>

#import "PLEnums.h"
#import "PLMath.h"
#import "PLIPanorama.h"
#import "PLCamera.h"
#import "PLViewDelegate.h"

#import "PLTransition.h"
#import "PLTransitionDelegate.h"

@class PLRenderer;

@interface PLViewBase : UIView <UIAccelerometerDelegate, PLTransitionDelegate> 
{
	/**member variables*/
@private
	PLRenderer *renderer;
	NSObject<PLIPanorama> *scene;
	
    NSTimer *animationTimer;
    NSTimeInterval animationInterval;
	
	BOOL isBlocked;
	
	CGPoint startPoint, endPoint;
	CGPoint startFovPoint, endFovPoint;
	
	BOOL isValidForFov;
	float fovDistance;
	NSUInteger fovCounter;
	
	BOOL isAccelerometerEnabled, isAccelerometerLeftRightEnabled, isAccelerometerUpDownEnabled;
	float accelerometerSensitivity;
	NSTimeInterval accelerometerInterval;
	
	BOOL isScrollingEnabled, isValidForScrolling, isScrolling;
	NSUInteger minDistanceToEnableScrolling;
	
	BOOL isInertiaEnabled, isValidForInertia;
	NSTimer *inertiaTimer;
	NSTimeInterval inertiaInterval;
	float inertiaStepValue;
	
	BOOL isResetEnabled, isShakeResetEnabled;
	uint8_t numberOfTouchesForReset;
	
	PLShakeData shakeData;
	float shakeThreshold;
	
	BOOL isValidForTouch;
	
	NSObject<PLViewDelegate> *delegate;
	
	BOOL displayLinkSupported, isDisplayLinkSupported;
	id displayLink;
	NSUInteger animationFrameInterval;
	BOOL isAccelerometerActivated;
	BOOL isAnimating;
    
    CMMotionManager *motionManager;
    NSTimer *motionTimer;
    CLLocationManager *locationManager;
    int lastAccelerometerPitch;
    float accelerometerPitch;
    float firstMagneticHeading, magneticHeading;
    PLSensorType sensorType;
    BOOL isSensorialRotationRunning;
	
	BOOL isValidForTransition;
	NSString * isValidForTransitionString;
	PLTransition *currentTransition;
	
	PLTouchStatus touchStatus;
	
	BOOL isPointerVisible;
}

/**properties*/

@property(nonatomic, retain) NSObject<PLIPanorama> *panorama;

@property(nonatomic, readonly, getter=getCamera) PLCamera *camera;

@property(nonatomic) NSTimeInterval animationInterval;
@property(nonatomic) NSUInteger animationFrameInterval;

@property(nonatomic) BOOL isBlocked;

@property(nonatomic) BOOL isAccelerometerEnabled, isAccelerometerLeftRightEnabled, isAccelerometerUpDownEnabled;
@property(nonatomic) float accelerometerSensitivity;
@property(nonatomic) NSTimeInterval accelerometerInterval;

@property(nonatomic) CGPoint startPoint, endPoint;
@property(nonatomic, readonly) CGPoint startFovPoint, endFovPoint;

@property(nonatomic) BOOL isScrollingEnabled;
@property(nonatomic) NSUInteger minDistanceToEnableScrolling;

@property(nonatomic) BOOL isInertiaEnabled;
@property(nonatomic) NSTimeInterval inertiaInterval;

@property(nonatomic) BOOL isResetEnabled, isShakeResetEnabled;
@property(nonatomic) uint8_t numberOfTouchesForReset;

@property(nonatomic, readonly) BOOL isValidForFov;

@property(nonatomic) float shakeThreshold;

@property(nonatomic) BOOL isDisplayLinkSupported;
@property(nonatomic, readonly) BOOL isAnimating, isSensorialRotationRunning;

@property(nonatomic, assign) NSObject<PLViewDelegate> *delegate;

@property(nonatomic, readonly, getter=getIsValidForTransition) BOOL isValidForTransition;

@property(nonatomic, readonly) PLTouchStatus touchStatus;
@property(nonatomic) BOOL isPointerVisible;

/**panorama methods*/

-(PLCamera *)getCamera;
-(void)setSceneAlpha:(float)value;
-(BOOL)getIsValidForTransition;

-(void)reset;
-(void)resetWithoutAlpha;
-(void)resetSceneAlpha;

-(void)drawView;
-(void)drawViewNTimes:(NSUInteger)times;
-(void)regenerateRenderBuffer;

-(void)startAnimation;
-(void)stopAnimation;

-(void)startSensorialRotation;
-(void)stopSensorialRotation;

-(BOOL)executeTransition:(PLTransition *)transition;

-(UIInterfaceOrientation)currentDeviceOrientation;

+(Class)layerClass;

@end