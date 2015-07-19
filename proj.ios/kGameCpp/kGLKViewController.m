//
//  kGLKViewController.m
//  kGame
//
//  Created by qiaokeli on 15/6/6.
//  Copyright (c) 2015年 qiaokeli. All rights reserved.
//

#import "kGLKViewController.h"

@implementation kGLKViewController

- (void)glkView:(GLKView *)view drawInRect:(CGRect)rect
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

- (void)update
{
	[self.view setNeedsDisplay];
}

- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event
{
	NSLog(@"touchesBegan:%@", event.description);
}

- (void)touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event
{
	NSLog(@"touchesCancelled:%@", event);
}

- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event
{
	NSLog(@"touchesEnded:%@", event);
}

- (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event
{
	NSLog(@"touchesMoved:%@", event);
}
@end
