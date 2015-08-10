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

static game::FirstGame s_game;

- (void)start
{
	CGRect sz = [[UIScreen mainScreen] bounds];
	CGFloat scale = [[UIScreen mainScreen] scale];
	kengine::kEngine::instance().start(sz.size.width * scale, sz.size.height * scale);
	s_game.start();
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
	
	NSTimeInterval deltaTime = [self timeSinceFirstResume];
	
	kengine::kEngine::instance().update(deltaTime);
	s_game.update(deltaTime);
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
