////////////////////////////////////////////////////////////////////////////
//
// Copyright 2016 Realm Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
////////////////////////////////////////////////////////////////////////////

#import <Foundation/Foundation.h>

#import <Realm/RLMObject.h>
#import <Realm/RLMProperty.h>

typedef NS_ENUM(NSUInteger, RLMSyncManagementObjectStatus) {
    RLMSyncManagementObjectStatusNotProcessed,
    RLMSyncManagementObjectStatusSuccess,
    RLMSyncManagementObjectStatusError,
};

NS_ASSUME_NONNULL_BEGIN

/**
 * This is the base class managing the meta info. The inheritance from the other
 * classes is assumed to be flattened out in the schema.
 */
@interface RLMSyncPermissionBaseObject : RLMObject

@property (readonly) NSString *id;
@property (readonly) NSDate *createdAt;
@property (readonly) NSDate *updatedAt;

// these both fields are filled by the server:
@property (readonly, nullable) NSNumber<RLMInt> *statusCode; // nil=not processed, 0=success, >0=error
@property (readonly, nullable) NSString *statusMessage;

@property (readonly) RLMSyncManagementObjectStatus status;

@end

NS_ASSUME_NONNULL_END
