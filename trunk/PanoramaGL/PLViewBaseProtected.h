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

#import "PLViewBase.h"
#import "PLIInitializeObject.h"

@interface PLViewBase(Protected) <PLIInitializeObject, CLLocationManagerDelegate>

@property(nonatomic, assign, getter=animationTimer, setter=setAnimationTimer:) NSTimer *animationTimer;
@property(nonatomic, assign, getter=displayLink, setter=setDisplayLink:) id displayLink;
@property(nonatomic, readonly, getter=scene) NSObject<PLIScene> *scene;
@property(nonatomic, readonly, getter=renderer) PLRenderer *renderer;

-(NSTimer *)animationTimer;
-(void)setAnimationTimer:(NSTimer *)timer;

-(id)displayLink;
-(void)setDisplayLink:(id)displayLink;

-(NSObject<PLIScene> *)scene;
-(PLRenderer *)renderer;

-(BOOL)calculateFov:(NSSet *)touches;

-(BOOL)executeDefaultAction:(NSSet *)touches eventType:(PLTouchEventType)type;
-(BOOL)executeResetAction:(NSSet *)touches;

-(BOOL)setAccelerometerDelegate:(id <UIAccelerometerDelegate>)accelerometerDelegate;
-(void)activateAccelerometer;
-(void)deactiveAccelerometer;

-(void)stopOnlyAnimation;
-(void)stopAnimationInternally;

-(void)startInertia;
-(void)stopInertia;
-(void)inertia;

-(void)activateOrientation;
-(void)deactiveOrientation;
-(void)changeOrientation:(UIDeviceOrientation)orientation;
-(void)orientationChanged:(UIDeviceOrientation)orientation;
-(BOOL)isOrientationValid:(UIDeviceOrientation)orientation;

-(BOOL)isTouchInView:(NSSet *)touches;
-(CGPoint)getLocationOfFirstTouch:(NSSet *)touches;

-(void)drawViewInternally;
-(void)drawViewInternallyNTimes:(NSUInteger)times;

-(BOOL)resetWithShake:(UIAcceleration *)acceleration;

-(void)setIsValidForTransition:(BOOL)value;

@end
