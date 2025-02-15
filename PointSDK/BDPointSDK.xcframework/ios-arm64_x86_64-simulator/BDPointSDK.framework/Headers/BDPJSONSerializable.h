//
//  Created by Bluedot Innovation.
//  Copyright © 2022 BlueDot. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Any object can be Json-serialized to a Dictionary of Foundation objects
 */
@protocol BDPJSONSerializable <NSObject>

/**
 *  @return the dicionary representing the object to be serialized
 */
- (NSDictionary * _Nullable)dictionaryRepresentation;

@end


/**
 * Any object can be Json-deserialized and instantiated from a Json Dictionary
 */
@protocol BDPJSONDeserializable <NSObject>

/**
 *  @return an instance of the object with details parsed from the input dictionary
 *
 *  @param dictionary The Json dictionary used for deserialization
 */
- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

@end

NS_ASSUME_NONNULL_END
