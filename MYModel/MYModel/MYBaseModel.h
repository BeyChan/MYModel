//
//  MYBaseModel.h
//  MYModel
//
//  Created by Melody Chan on 16/10/13.
//  Copyright © 2016年 canlife. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MYBaseModel : NSObject<NSCoding>{
}

-(id)initWithDataDic:(NSDictionary*)data;
- (NSDictionary*)attributeMapDictionary;
- (void)setAttributes:(NSDictionary*)dataDic;
- (NSString *)customDescription;
- (NSString *)description;
- (NSData*)getArchivedData;

- (NSString *)cleanString:(NSString *)str;    //清除\n和\r的字符串

@end
