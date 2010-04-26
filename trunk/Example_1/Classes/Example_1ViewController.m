/*
 * This file is part of the PanoramaGL examples.
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

#import "Example_1ViewController.h"
#import "PLTexture.h"

@interface Example_1ViewController ()

- (void)loadImage:(NSString *)name;

@end


@implementation Example_1ViewController

@synthesize plView;
@synthesize viewImageContainer;

/*
// The designated initializer. Override to perform setup that is required before the view is loaded.
- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
    if (self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil]) {
        // Custom initialization
    }
    return self;
}
*/

/*
// Implement loadView to create a view hierarchy programmatically, without using a nib.
- (void)loadView {
}
*/

// Implement viewDidLoad to do additional setup after loading the view, typically from a nib.
- (void)viewDidLoad {
	[super viewDidLoad];
	//Example with Spherical type
	plView.isDeviceOrientationEnabled = NO;
	plView.isAccelerometerEnabled = NO;
	plView.isScrollingEnabled = NO;
	plView.isInertiaEnabled = NO;
	plView.type = PLViewTypeSpherical;
	[self loadImage:@"mitadmundo"];
}

// Override to allow orientations other than the default portrait orientation.
- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation {
	CGRect frame = plView.frame;
	switch (interfaceOrientation) 
	{
		case UIInterfaceOrientationPortrait:
		case UIInterfaceOrientationPortraitUpsideDown:
			viewImageContainer.hidden = NO;
			frame.size.width = 320;
			frame.size.height = 340;
			plView.frame = frame;
			break;
		case UIInterfaceOrientationLandscapeLeft:
		case UIInterfaceOrientationLandscapeRight:
			viewImageContainer.hidden = YES;
			frame.size.width = 480;
			frame.size.height = 320;
			plView.frame = frame;
			break;
	}
    // Return YES for supported orientations
    return YES;
}

- (void)didReceiveMemoryWarning {
	// Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
	
	// Release any cached data, images, etc that aren't in use.
}

- (void)viewDidUnload {
	// Release any retained subviews of the main view.
	// e.g. self.myOutlet = nil;
}

//Functions
- (void)loadImage:(NSString *)name
{
	[plView stopAnimation];
	[plView removeAllTextures];
	[plView addTextureAndRelease:[PLTexture textureWithPath:[[NSBundle mainBundle] pathForResource:name ofType:@"jpg"]]];
	[plView reset];
	[plView drawView];
}

//Events
- (IBAction) clickOnImage1:(id)sender
{
	[self loadImage:@"mitadmundo"];
}

- (IBAction) clickOnImage2:(id)sender
{
	[self loadImage:@"espe"];
}

- (void)dealloc 
{
	if(viewImageContainer)
		[viewImageContainer release];
	if(plView)
		[plView release];
    [super dealloc];
}

@end
