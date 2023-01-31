//
//  Created by Bluedot Innovation.
//  Copyright © 2022 BlueDot. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Any object can be Json-serialized to a Dictionary of Foundation objects
 @copyright Bluedot Innovation
 */
@protocol BDPJSONSerializable <NSObject>

/**
 *  @return the dicionary representing the object to be serialized
 */
- (NSDictionary * _Nullable)dictionaryRepresentation;

@end


/**
 @brief Any object can be Json-deserialized and instantiated from a Json Dictionary
 @copyright Bluedot Innovation
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
