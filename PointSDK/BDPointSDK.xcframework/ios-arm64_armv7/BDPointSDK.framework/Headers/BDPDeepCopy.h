//
//  Created by Bluedot Innovation
//  Copyright © 2016 Bluedot Innovation. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
  @brief An object which may be <a href="http://en.wikipedia.org/wiki/Object_copy#Deep_copy">deep copied</a>.

  <p>Whereas the <a href="https://developer.apple.com/library/mac/documentation/Cocoa/Reference/Foundation/Protocols/NSCopying_Protocol/Reference/Reference.html">NSCopying</a>
  Protocol is typically used to define shallow copying; @ref BDPDeepCopy specifies a copying method that must return a
  deep-copy.  That is, an entirely new object graph which is identical to the receiver and its referenced objects.</p>

  <p>There may be application specific exceptions to this definition, for example where those referenced objects are
  singletons.</p>

  @see http://en.wikipedia.org/wiki/Object_copy For a fuller explanation of deep vs. shallow copying
*/
@protocol BDPDeepCopy <NSObject>

/**
 * @returns a deep-copy of this object.
 */
- (id)deepCopy;

@end
