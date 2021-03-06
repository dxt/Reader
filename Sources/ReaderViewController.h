//
//	ReaderViewController.h
//	Reader v2.8.6
//
//	Created by Julius Oklamcak on 2011-07-01.
//	Copyright © 2011-2015 Julius Oklamcak. All rights reserved.
//
//	Permission is hereby granted, free of charge, to any person obtaining a copy
//	of this software and associated documentation files (the "Software"), to deal
//	in the Software without restriction, including without limitation the rights to
//	use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
//	of the Software, and to permit persons to whom the Software is furnished to
//	do so, subject to the following conditions:
//
//	The above copyright notice and this permission notice shall be included in all
//	copies or substantial portions of the Software.
//
//	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//	OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
//	WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
//	CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//

#import <UIKit/UIKit.h>

#import "ReaderConstants.h"

#if (READER_USE_SN_BASE_VIEW_CONTROLLER == TRUE)
#import "SNBaseViewController.h"
#endif

#import "ReaderDocument.h"

@class ReaderViewController;
@class ReaderContentView;
@class ReaderDocument;
@class ReaderMainPagebar;

@protocol ReaderViewControllerDelegate <NSObject>

@optional // Delegate protocols

- (void)dismissReaderViewController:(ReaderViewController *)viewController;

@end

#if (READER_USE_SN_BASE_VIEW_CONTROLLER == TRUE)
@interface ReaderViewController : SNBaseViewController
#else
@interface ReaderViewController : UIViewController
#endif

@property (nonatomic, weak, readwrite) id <ReaderViewControllerDelegate> delegate;

@property (nonatomic, readonly) ReaderDocument *document;
@property (nonatomic, readonly) UIScrollView *scrollView;
@property (nonatomic, readonly) ReaderMainPagebar *mainPagebar;
@property (nonatomic, readonly) NSDictionary *contentViews;
@property (nonatomic, readonly) NSInteger currentPage;

@property (nonatomic, readonly) CGFloat pagebarHeight;

- (instancetype)initWithReaderDocument:(ReaderDocument *)object;
- (instancetype)initWithReaderDocument:(ReaderDocument *)object showPagebar:(BOOL)showPagebar;

- (void)showDocumentPage:(NSInteger)page;
- (void)decrementPageNumber;
- (void)incrementPageNumber;

- (void)reloadCurrentPage;
- (void)reloadAllPages;

- (void)offsetCurentPageFrame:(CGFloat)yOffset;
- (void)reduceCurrentPageFrameHeight:(CGFloat)reduceAmount;
- (BOOL)currentPageFrameIsStandard;
- (CGFloat)currentPageFrameOffset;
- (void)standardizeCurrentPageFrame;

- (void)didShowDocument;
- (void)createdContentView:(ReaderContentView *)contentView forPage:(NSInteger)pageNumber;
- (void)didShowDocumentPage:(NSInteger)page;

@end
