# PanoramaGL Library #

---


**PanoramaGL library** was the first **open source** library in the world to see panoramic views on the  iPhone and iPod Touch.

The supported features in version _**0.1**_ are:

- Run on iPhone, iPod Touch and iPad <br />
- Tested with SDK 4.x to 5.x <br />
- Supports OpenGL ES 1.1<br />
- Supports spherical, cubic and cylindrical panoramic images<br />
- Allows scrolling and continuous scrolling<br />
- Supports scrolling left to right and from top to bottom using the accelerometer<br />
- Allows to use the inertia to stop scrolling<br />
- Supports zoom in and zoom out (moving two fingers on the screen)<br />
- Supports reset (placing three fingers on the screen or shaking the device)<br />
- Allows you to control the range of rotation in the x and y axis<br />
- Support for view events<br />
- Support for hotspots<br />
- Support for movement with simulated gyroscope (Only compatible with devices with Magnetometer and Accelerometer)<br />

## **Version 0.1 (July/2012):** ##

---


### Bugs fixes: ###

- Appearance of images (distortion) when orientation change.<br />
- Render problems with iOS >= 4.x.<br />
- Memory leaks.<br />

### Improvements: ###

- Change of LGPL license to Apache 2.0 license.<br />
- Support for iOS >= 4.x.<br />
- Support for iPad.<br />
- Support for Hotspots (see PLHotspot class).<br />
- Spherical images supports up 2048x1024 texture (see PLSpherical2Panorama class).<br />
- Support for simulated gyroscope (see startSensorialRotation method on PLView class).<br />
- Support for simple JSON protocol (see PLJSONLoader class and load method on PLView class).<br />

## Resources: ##

---


**Docs:** [User Guide](http://code.google.com/p/panoramagl/wiki/UserGuide)

**Code:** [Source Code ](http://panoramagl.googlecode.com/files/PanoramaGL_0.1.zip)  - [Example](http://panoramagl.googlecode.com/files/HelloPanoramaGL.zip)

**Video:** [HelloPanorama Example](http://www.youtube.com/watch?v=1eSnM9eL3l0)

**Author:** _**[Javier Baez](mailto:javbaezga@gmail.com)**_ _**<[javbaezga@gmail.com](mailto:javbaezga@gmail.com)>**_
<br />
## Supporting this project: ##

---


If you want to support this project, please donate to my Paypal account

[![](https://www.paypal.com/en_US/i/btn/btn_donateCC_LG.gif)](https://www.paypal.com/cgi-bin/webscr?cmd=_donations&business=TN942N9FFXYEL&lc=EC&item_name=PanoramaGL&currency_code=USD&bn=PP%2dDonationsBF%3abtn_donateCC_LG%2egif%3aNonHosted)

Please add credits in your projects when using PanoramaGL library.