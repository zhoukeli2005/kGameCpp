//
//  kGLKViewController.m
//  kGame
//
//  Created by qiaokeli on 15/6/6.
//  Copyright (c) 2015年 qiaokeli. All rights reserved.
//

#import "kGLKViewController.h"
#import "kEngine.h"
#import "FirstGame.h"

@implementation kGLKViewController

- (void)start
{
	CGRect sz = [[UIScreen mainScreen] bounds];
	kengine::kEngine::instance().start(sz.size.width, sz.size.height);
	
	static game::FirstGame game;
	game.start();
}

- (void)glkView:(GLKView *)view drawInRect:(CGRect)rect
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	
	kengine::kEngine::instance().draw();
}

- (void)update
{
	[self.view setNeedsDisplay];
	
	kengine::kEngine::instance().update([self timeSinceLastUpdate]);
}

- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event
{
	NSLog(@"touchesBegan:%@", event.description);
	kengine::kEngine::instance().touchesBegan();
}

- (void)touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event
{
	NSLog(@"touchesCancelled:%@", event);
	kengine::kEngine::instance().touchesCanceled();
}

- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event
{
	NSLog(@"touchesEnded:%@", event);
	kengine::kEngine::instance().touchesEnded();
}

- (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event
{
	NSLog(@"touchesMoved:%@", event);
	kengine::kEngine::instance().touchesMoved();
}
@end
