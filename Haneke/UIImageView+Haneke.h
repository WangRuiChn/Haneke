//
//  UIImageView+Haneke.h
//  Haneke
//
//  Created by Hermes Pique on 12/02/14.
//  Copyright (c) 2014 Hermes Pique. All rights reserved.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

#import <UIKit/UIKit.h>
#import "HNKCache.h"

@interface UIImageView (Haneke)

/** Loads, resizes, displays and caches an appropiately sized image from the given path.
 @param path Path from which the image will be loaded if it's not available in the cache.
 @see hnk_setImageFromFile:placeholderImage:success:failure:
 **/
- (void)hnk_setImageFromFile:(NSString*)path;

/** Loads, resizes, displays and caches an appropiately sized image from the given path.
 @param path Path from which the image will be loaded if it's not available in the cache.
 @param placeholderImage Image to be used as a placeholder until the requested image is ready. The placeholder image will only be used if the requested image is not available in the memory cache. If nil, the image view will not change its image until the requested image is ready.
 @see hnk_setImageFromFile:placeholderImage:success:failure:
 **/
- (void)hnk_setImageFromFile:(NSString*)path placeholderImage:(UIImage*)placeholderImage;

/** Loads, resizes, displays and caches an appropiately sized image from the given path. If a success block is provided you will be responsible for setting the image.
 @param path Path from which the image will be loaded if it's not available in the cache.
 @param successBlock Block to be called when the requested image is ready to be set. If provided, the block is reponsible for setting the image. Can be nil.
 @param failureBlock Block to be called if an error occurs. The most likely cause of error is that the given path does not contain an image. Can be nil.
 @warning If a success block is provided you will be responsible for setting the image.
 @see hnk_setImageFromFile:placeholderImage:success:failure:
 **/
- (void)hnk_setImageFromFile:(NSString*)path success:(void (^)(UIImage *image))successBlock failure:(void (^)(NSError *error))failureBlock;

/** Loads, resizes, displays and caches an appropiately sized image from the given path. If a success block is provided you will be responsible for setting the image.
 @param path Path from which the image will be loaded if it's not available in the cache.
 @param placeholderImage Image to be used as a placeholder until the requested image is ready. The placeholder image will only be used if the requested image is not available in the memory cache. If nil, the image view will not change its image until the requested image is ready.
 @param successBlock Block to be called when the requested image is ready to be set. If provided, the block is reponsible for setting the image. Can be nil.
 @param failureBlock Block to be called if an error occurs. The most likely cause of error is that the given path does not contain an image. Can be nil.
 @discussion Retrieves an appropiately sized image (based on the bounds and contentMode of the UIImageView) from the memory or disk cache. Disk access is performed in background. If not cached, loads the original image from disk, produces an appropiately sized image and caches the result, everything in background.
 @discussion If no success block is provided, the requested image will be set with a short fade transition, or synchronously and without transition when retrieved from the memory cache.
 @discussion If needed, the least recently used images in the cache will be evicted in background.
 @discussion If the success block is nil, the image will be set with a short fade transition, or inmmediatly if the image was retrieved from the memory cache.
 @warning If a success block is provided you will be responsible for setting the image.  
 **/
- (void)hnk_setImageFromFile:(NSString*)path placeholderImage:(UIImage*)placeholderImage success:(void (^)(UIImage *image))successBlock failure:(void (^)(NSError *error))failureBlock;

/** Loads, resizes, displays and caches an appropiately sized image from the given url.
 @param url Url from which the image will be loaded if it's not available in the cache.
 @see hnk_setImageFromURL:placeholderImage:success:failure:
 **/
- (void)hnk_setImageFromURL:(NSURL*)url;

/** Loads, resizes, displays and caches an appropiately sized image from the given url.
 @param url Url from which the image will be loaded if it's not available in the cache.
 @param placeholderImage Image to be used as a placeholder until the requested image is ready. The placeholder image will only be used if the requested image is not available in the memory cache. If nil, the image view will not change its image until the requested image is ready.
 @see hnk_setImageFromURL:placeholderImage:success:failure:
 **/
- (void)hnk_setImageFromURL:(NSURL*)url placeholderImage:(UIImage*)placeholderImage;

/** Loads, resizes, displays and caches an appropiately sized image from the given url. If a success block is provided you will be responsible for setting the image.
 @param url Url from which the image will be loaded if it's not available in the cache.
 @param successBlock Block to be called when the requested image is ready to be set. If provided, the block is reponsible for setting the image. Can be nil.
 @param failureBlock Block to be called if an error occurs. The most likely cause of error is that the given path does not contain an image. Can be nil.
 @warning If a success block is provided you will be responsible for setting the image.
 @see hnk_setImageFromURL:placeholderImage:success:failure:
 **/
- (void)hnk_setImageFromURL:(NSURL*)url success:(void (^)(UIImage *image))successBlock failure:(void (^)(NSError *error))failureBlock;

/** Loads, resizes, displays and caches an appropiately sized image from the given url. If a success block is provided you will be responsible for setting the image.
 @param url Url from which the image will be loaded if it's not available in the cache.
 @param placeholderImage Image to be used as a placeholder until the requested image is ready. The placeholder image will only be used if the requested image is not available in the memory cache. If nil, the image view will not change its image until the requested image is ready.
 @param successBlock Block to be called when the requested image is ready to be set. If provided, the block is reponsible for setting the image. Can be nil.
 @param failureBlock Block to be called if an error occurs. The most likely cause of error is that the given path does not contain an image. Can be nil.
 @discussion Retrieves an appropiately sized image (based on the bounds and contentMode of the UIImageView) from the memory or disk cache. Disk access is performed in background. If not cached, loads the original image from the given url, produces an appropiately sized image and caches the result, everything in background.
 @discussion If no success block is provided, the requested image will be set with a short fade transition, or synchronously and without transition when retrieved from the memory cache.
 @discussion If needed, the least recently used images in the cache will be evicted in background.
 @warning If a success block is provided you will be responsible for setting the image.
 **/
- (void)hnk_setImageFromURL:(NSURL*)url placeholderImage:(UIImage*)placeholderImage success:(void (^)(UIImage *image))successBlock failure:(void (^)(NSError *error))failureBlock;

/** Resizes, displays and caches an appropiately sized image from the given image.
 **/
- (void)hnk_setImage:(UIImage*)image withKey:(NSString*)key;

/** Loads, resizes, displays and caches an appropiately sized image from the given entity.
 **/
 - (void)hnk_setImageFromEntity:(id<HNKCacheEntity>)entity;

/**
 Cancels the current image request, if any. 
 @discussion It is recommended to call this from [UITableViewCell prepareForReuse] or [UICollectionViewCell prepareForReuse], or as soon as you don't need the image view anymore.
 **/
- (void)hnk_cancelImageRequest;

@property (nonatomic, strong) HNKCacheFormat *hnk_cacheFormat;

@end

enum
{
    HNKErrorImageFromURLMissingData = -400,
};
