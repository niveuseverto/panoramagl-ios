# Introduction #

This guide is a simple guideline to use _**PanoramaGL 0.1**_ library, for more details please check _**[HelloPanoramaGL](http://panoramagl.googlecode.com/files/HelloPanoramaGL.zip)**_ example.

# Details #

## 1. How to import PanoramaGL library? ##

---


a. Download _**[PanoramaGL\_0.1.zip](http://panoramagl.googlecode.com/files/PanoramaGL_0.1.zip)**_ or download the source code from _**[repository](http://code.google.com/p/panoramagl/source/checkout)**_<br />
b. If you download the zip file then descompress the file<br />
c. Copy PanoramaGL folder inside your project folder<br />
d. Import PanoramaGL folder in your project (You can drag and drop the folder inside XCode)<br />
f. Import the frameworks:
_* CoreMotion
  * CoreLocation
  * MobileCoreServices
  * SystemConfiguration
  * QuartzCore
  * OpenGLES
  * CFNetwork
  * UIKit
  * Foundation
  * CoreGraphics_
g. Import the libraries:
_* libxml2.dylib
  * libz.dylib_

To import frameworks and libraries you must:
> i. Select you project (select the root)<br />
> ii. Go to **"TARGETS"** and select the project<br />
> iii. Select **"Build Phases"** option<br />
> iv. Go to **"Link Binary With Libraries"** panel<br />
> v. Select **"+"** option<br />
> vi. Select frameworks and libraries in the list (Use cmd key for multiple options)<br />
> vii. Click on **"Add"** button<br />

## 2. How to use PanoramaGL in your app? ##

---

For next example, I have imported a spherical image named pano.jpg in the project.

### 2.1. With Interface Builder ###

a. Create a ViewController<br />
b. Open ViewController with Interface Builder<br />
c. Select the View in **"Objects"** panel<br />
d. Show **"Identity Inspector"** (View->Utilities->Show Identity Inspector or Alt+Cmd+5)<br />
e. Change in **"Custom Class"** the Class from UIView to PLView<br />
f. Go to ViewController.h and import PLView.h
```
    #import "PLView.h"
```
g. Open ViewController.m, go to viewDidLoad method and put this code:
```
    PLView *plView = (PLView *)self.view;
    PLSpherical2Panorama *panorama = [PLSpherical2Panorama panorama];
    [panorama setImage:[PLImage imageWithPath:[[NSBundle mainBundle] pathForResource:@"pano" ofType:@"jpg"]]];
    [plView setPanorama:panorama];
```

### 2.2. Only with code ###

a. Import PLView.h in your class
```
    #import "PLView.h"
```
b. Create a variable of type PLView
```
    PLView *plView;
```
c. Create the view
```
    plView = [[PLView alloc] initWithFrame:CGRectMake(x,y,w,h)]);
```
d. Load panorama:
```
    PLView *plView = [[PLView alloc] initWithFrame:CGRectMake(0, 0, 320, 480)];
    PLSpherical2Panorama *panorama = [PLSpherical2Panorama panorama];
    [panorama setImage:[PLImage imageWithPath:[[NSBundle mainBundle] pathForResource:@"pano" ofType:@"jpg"]]];
    [plView setPanorama:panorama];
```
e. Add panorama view to the window or view:
```
    [window addSubview:plView] or [your_view addSubview:plView]
```
f. Release the view
```
    [plView release];
```

## 3. Simple JSON Protocol ##

---

Also, you can use JSON protocol to load panoramas.

**_Note:_** JSON protocol is limited for local files in this version.

### 3.1. Source code: ###

```
    [plView load:[PLJSONLoader loaderWithPath:[[NSBundle mainBundle] pathForResource:@"json" ofType:@"data"]]];
```
**_Note:_** For this code, I have a file named json.data in my app.

### 3.2. JSON Protocol: ###

```
{
    "urlBase": "res://",        //This is always res:// (this feature will be improve for support http protocol)
    "type": "spherical",        //Panorama type: spherical, spherical2, cubic, cylindrical
    "sensorialRotation": false, //Simulated gyroscope [true, false] (Optional)
    "images":                   //Panoramic images section
    {
        "preview": "preview.jpg",  //Preview image (Optional, this option will be used with http protocol)
        "image": "pano.jpg"     //Panoramic image name for spherical, spherical2 and cylindrical panoramas
        "front": "front.jpg",   //Front image for cubic panorama (only use with cubic panorama)
        "back": "back.jpg",     //Back image for cubic panorama (only use with cubic panorama)
        "left": "left.jpg",     //Left image for cubic panorama (only use with cubic panorama)
        "right": "right.jpg",   //Right image for cubic panorama (only use with cubic panorama)
        "up": "up.jpg",         //Up image for cubic panorama (only use with cubic panorama)
        "down": "down.jpg"      //Down image for cubic panorama (only use with cubic panorama)
    },
    "camera":                   //Camera settings section (Optional)
    {
        "vlookat": 0,           //Initial vertical position [-90, 90]
        "hlookat": 0,           //Initial horizontal position [-180, 180]
        "atvmin": -90,          //Min vertical position [-90, 90]
        "atvmax": 90,           //Max vertical position [-90, 90]
        "athmin": -180,         //Min horizontal position [-180, 180]
        "athmax": 180           //Max horizontal position [-180, 180]
    },
    "hotspots": [               //Hotspots section (Optional, this section is an array of hotspots)
                 {
                 "id": 1,               //Hotspot identifier (long)
                 "atv": 0,              //Vertical position [-90, 90]
                 "ath": 0,              //Horizontal position [-180, 180]
                 "width": 0.08,         //Width
                 "height": 0.08,        //Height
                 "image": "hotspot.png" //Image
                 }
                 ]
}
```

### 3.3. See: ###

_PLJSONLoader_ class and _PLView_ load method.<br />
_json.data_, _json\_s2.data_ and _json\_cubic.data_ on _**[HelloPanoramaGL](http://panoramagl.googlecode.com/files/HelloPanoramaGL.zip)**_ example.

## 4. More information ##

---

For more details, please check _**[HelloPanoramaGL](http://panoramagl.googlecode.com/files/HelloPanoramaGL.zip)**_ example.<br />
This example is compatible for iPhone, iPod Touch and iPad.