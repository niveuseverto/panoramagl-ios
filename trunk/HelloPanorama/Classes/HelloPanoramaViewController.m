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

#import "HelloPanoramaViewController.h"

@implementation HelloPanoramaViewController

@synthesize plView;

/*
// The designated initializer. Override to perform setup that is required before the view is loaded.
- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil 
{
    if (self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil]) 
    {
        // Custom initialization
    }
    return self;
}
*/

/*
// Implement loadView to create a view hierarchy programmatically, without using a nib.
- (void)loadView 
{
}
*/

// Implement viewDidLoad to do additional setup after loading the view, typically from a nib.
- (void)viewDidLoad 
{
	[super viewDidLoad];
	//Example with Spherical type
	plView.isDeviceOrientationEnabled = YES;
	plView.isAccelerometerEnabled = YES;
	plView.isScrollingEnabled = YES;
	plView.isInertiaEnabled = YES;
	plView.type = PLViewTypeSpherical;
	[plView addTexture:[PLTexture textureWithPath:[[NSBundle mainBundle] pathForResource:@"pano" ofType:@"jpg"]]];
	
	/*
	//Example with Cube Faces type (you need an image for each cube face)
	plView.type = PLViewTypeCubeFaces;
	[plView addTexture:[PLTexture textureWithPath:[[NSBundle mainBundle] pathForResource:@"front" ofType:@"jpg"]]];
	[plView addTexture:[PLTexture textureWithPath:[[NSBundle mainBundle] pathForResource:@"back" ofType:@"jpg"]]];
	[plView addTexture:[PLTexture textureWithPath:[[NSBundle mainBundle] pathForResource:@"left" ofType:@"jpg"]]];
	[plView addTexture:[PLTexture textureWithPath:[[NSBundle mainBundle] pathForResource:@"right" ofType:@"jpg"]]];
	[plView addTexture:[PLTexture textureWithPath:[[NSBundle mainBundle] pathForResource:@"top" ofType:@"jpg"]]];
	[plView addTexture:[PLTexture textureWithPath:[[NSBundle mainBundle] pathForResource:@"bottom" ofType:@"jpg"]]];
	*/
}

// Override to allow orientations other than the default portrait orientation.
- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation 
{
    // Return YES for supported orientations
    return NO;
}

- (void)didReceiveMemoryWarning 
{
	// Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
	// Release any cached data, images, etc that aren't in use.
}

- (void)viewDidUnload 
{
	// Release any retained subviews of the main view.
	// e.g. self.myOutlet = nil;
}

- (void)dealloc 
{
	[plView release];
    [super dealloc];
}

@end
