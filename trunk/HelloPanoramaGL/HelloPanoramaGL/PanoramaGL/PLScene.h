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

#import "PLRenderableElementBase.h"
#import "PLIScene.h"

@interface PLScene : PLRenderableElementBase <PLIScene>
{
	/**member variables*/
@private
	NSMutableArray *cameras;
	PLCamera *currentCamera;
	NSUInteger cameraIndex;
	NSMutableArray *elements;
	PLViewBase *view;
}

/**init methods*/

+(id)scene;
+(id)sceneWithCamera:(PLCamera *)camera;
+(id)sceneWithElement:(PLSceneElement *)element;
+(id)sceneWithElement:(PLSceneElement *)element camera:(PLCamera *)camera;

+(id)sceneWithView:(PLViewBase *)view;
+(id)sceneWithView:(PLViewBase *)view camera:(PLCamera *)camera;
+(id)sceneWithView:(PLViewBase *)view element:(PLSceneElement *)element;
+(id)sceneWithView:(PLViewBase *)view element:(PLSceneElement *)element camera:(PLCamera *)camera;

@end
