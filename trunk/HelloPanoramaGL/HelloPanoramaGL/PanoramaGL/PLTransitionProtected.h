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
#import "PLTransition.h"

@interface PLTransition(Protected)

@property(nonatomic, assign, getter=timer, setter=setTimer:) NSTimer *timer;
@property(nonatomic, readonly, getter=view) PLViewBase *view;
@property(nonatomic, readonly, getter=scene) PLScene *scene;

-(NSTimer *)timer;
-(void)setTimer:(NSTimer *)timer;

-(PLViewBase *)view;
-(PLScene *)scene;

-(void)beginExecute;
-(void)endExecute;

-(void)process;
-(BOOL)processInternally;

-(void)setProgressPercentage:(NSUInteger)value;

@end

