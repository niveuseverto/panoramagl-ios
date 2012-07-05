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

@class PLViewBase;

#import "PLStructs.h"
#import "PLTransition.h"
#import "PLHotspot.h"

@protocol PLViewDelegate

@optional

-(void)view:(PLViewBase *)plView touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event;
-(void)view:(PLViewBase *)plView touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event;
-(void)view:(PLViewBase *)plView touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event;

-(BOOL)view:(PLViewBase *)plView shouldBeginTouching:(NSSet *)touches withEvent:(UIEvent *)event;
-(void)view:(PLViewBase *)plView didBeginTouching:(NSSet *)touches withEvent:(UIEvent *)event;
-(BOOL)view:(PLViewBase *)plView shouldTouch:(NSSet *)touches withEvent:(UIEvent *)event;
-(void)view:(PLViewBase *)plView didTouch:(NSSet *)touches withEvent:(UIEvent *)event;
-(BOOL)view:(PLViewBase *)plView shouldEndTouching:(NSSet *)touches withEvent:(UIEvent *)event;
-(void)view:(PLViewBase *)plView didEndTouching:(NSSet *)touches withEvent:(UIEvent *)event;

-(BOOL)view:(PLViewBase *)plView shouldAccelerate:(UIAcceleration *)acceleration withAccelerometer:(UIAccelerometer *)accelerometer;
-(void)view:(PLViewBase *)plView didAccelerate:(UIAcceleration *)acceleration withAccelerometer:(UIAccelerometer *)accelerometer;

-(BOOL)view:(PLViewBase *)plView shouldBeginInertia:(CGPoint)starPoint endPoint:(CGPoint)endPoint;
-(void)view:(PLViewBase *)plView didBeginInertia:(CGPoint)starPoint endPoint:(CGPoint)endPoint;
-(BOOL)view:(PLViewBase *)plView shouldRunInertia:(CGPoint)starPoint endPoint:(CGPoint)endPoint;
-(void)view:(PLViewBase *)plView didRunInertia:(CGPoint)starPoint endPoint:(CGPoint)endPoint;
-(void)view:(PLViewBase *)plView didEndInertia:(CGPoint)starPoint endPoint:(CGPoint)endPoint;

-(BOOL)viewShouldReset:(PLViewBase *)plView;
-(void)viewDidReset:(PLViewBase *)plView;

-(BOOL)viewShouldBeginZooming:(PLViewBase *)plView;
-(void)view:(PLViewBase *)plView didBeginZooming:(CGPoint)starPoint endPoint:(CGPoint)endPoint;
-(BOOL)view:(PLViewBase *)plView shouldRunZooming:(float)distance isZoomIn:(BOOL)isZoomIn isZoomOut:(BOOL)isZoomOut;
-(void)view:(PLViewBase *)plView didRunZooming:(float)distance isZoomIn:(BOOL)isZoomIn isZoomOut:(BOOL)isZoomOut;
-(void)view:(PLViewBase *)plView didEndZooming:(float)distance isZoomIn:(BOOL)isZoomIn isZoomOut:(BOOL)isZoomOut;

-(BOOL)view:(PLViewBase *)plView shouldBeginMoving:(CGPoint)starPoint endPoint:(CGPoint)endPoint;
-(void)view:(PLViewBase *)plView didBeginMoving:(CGPoint)starPoint endPoint:(CGPoint)endPoint;
-(BOOL)view:(PLViewBase *)plView shouldRunMoving:(CGPoint)starPoint endPoint:(CGPoint)endPoint;
-(void)view:(PLViewBase *)plView didRunMoving:(CGPoint)starPoint endPoint:(CGPoint)endPoint;
-(void)view:(PLViewBase *)plView didEndMoving:(CGPoint)starPoint endPoint:(CGPoint)endPoint;

-(BOOL)view:(PLViewBase *)plView shouldBeingScrolling:(CGPoint)starPoint endPoint:(CGPoint)endPoint;
-(void)view:(PLViewBase *)plView didBeginScrolling:(CGPoint)starPoint endPoint:(CGPoint)endPoint;
-(BOOL)view:(PLViewBase *)plView shouldScroll:(CGPoint)starPoint endPoint:(CGPoint)endPoint;
-(void)view:(PLViewBase *)plView didScroll:(CGPoint)starPoint endPoint:(CGPoint)endPoint;
-(void)view:(PLViewBase *)plView didEndScrolling:(CGPoint)starPoint endPoint:(CGPoint)endPoint;

-(void)view:(PLViewBase *)plView didBeginTransition:(PLTransition *)transition;
-(void)view:(PLViewBase *)plView didProcessTransition:(PLTransition *)transition progressPercentage:(NSUInteger)progressPercentage;
-(void)view:(PLViewBase *)plView didEndTransition:(PLTransition *)transition;

-(void)view:(PLViewBase *)plView didOverHotspot:(PLHotspot *)hotspot screenPoint:(CGPoint)point scene3DPoint:(PLPosition)position;
-(void)view:(PLViewBase *)plView didOutHotspot:(PLHotspot *)hotspot screenPoint:(CGPoint)point scene3DPoint:(PLPosition)position;
-(void)view:(PLViewBase *)plView didClickHotspot:(PLHotspot *)hotspot screenPoint:(CGPoint)point scene3DPoint:(PLPosition)position;

@end