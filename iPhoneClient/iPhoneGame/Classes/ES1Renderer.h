//
//  ES1Renderer.h
//  iPhoneGame
//
//  Created by svp on 09.02.10.
//  Copyright __MyCompanyName__ 2010. All rights reserved.
//

#import "ESRenderer.h"

#import <OpenGLES/ES1/gl.h>
#import <OpenGLES/ES1/glext.h>

@interface ES1Renderer : NSObject <ESRenderer>
{
@private
	EAGLContext *context;
	
	// The pixel dimensions of the CAEAGLLayer
	GLint backingWidth;
	GLint backingHeight;
	
	// The OpenGL names for the framebuffer and renderbuffer used to render to this view
	GLuint defaultFramebuffer, colorRenderbuffer;
}

- (void) render;
- (BOOL) resizeFromLayer:(CAEAGLLayer *)layer;

@end
