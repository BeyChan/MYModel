# MYModel
两种用法
用法一:
/**
 Provide some data-model method:
 提供一些数据模型方法

 *转化json为任何对象，或转换任何对象为json
 通过key-value字典设置对象属性(像KVC)
 实现"NSCoding","NSCopying","-hash"和"isEqual:"
 
 See `MYModel` protocol for custom methods.
 看MYModel协议通过方法
 Sample Code:
 
 ********************** json convertor *********************
 @interface MYAuthor : NSObject
 @property (nonatomic, strong) NSString *name;
 @property (nonatomic, assign) NSDate *birthday;
 @end
 @implementation MYAuthor
 @end
 
 @interface MYBook : NSObject
 @property (nonatomic, copy) NSString *name;
 @property (nonatomic, assign) NSUInteger pages;
 @property (nonatomic, strong) MYAuthor *author;
 @end
 @implementation MYBook
 @end
 
 int main() {
 // create model from json
 MYBook *book = [MYBook MY_modelWithJSON:@"{\"name\": \"Harry Potter\", \"pages\": 256, \"author\": {\"name\": \"J.K.Rowling\", \"birthday\": \"1965-07-31\" }}"];
 
 // convert model to json
 NSString *json = [book MY_modelToJSONString];
 // {"author":{"name":"J.K.Rowling","birthday":"1965-07-31T00:00:00+0000"},"name":"Harry Potter","pages":256}
 }
 
 ********************** Coding/Copying/hash/equal *********************
 @interface MYShadow :NSObject <NSCoding, NSCopying>
 @property (nonatomic, copy) NSString *name;
 @property (nonatomic, assign) CGSize size;
 @end
 
 @implementation MYShadow
 - (void)encodeWithCoder:(NSCoder *)aCoder { [self MY_modelEncodeWithCoder:aCoder]; }
 - (id)initWithCoder:(NSCoder *)MYecoder { self = [super init]; return [self MY_modelInitWithCoder:MYecoder]; }
 - (id)copyWithZone:(NSZone *)zone { return [self MY_modelCopy]; }
 - (NSUInteger)hash { return [self MY_modelHash]; }
 - (BOOL)isEqual:(id)object { return [self MY_modelIsEqual:object]; }
 @end
 
 */
 
 
用法二:
继承MYBaseModel
一般命名只要不是id,均可以自动转换成模型

@interface MYTestModel :MYBaseModel <NSCoding, NSCopying>
 @property (nonatomic, copy) NSString *name;
 @property (nonatomic, copy) NSString *userId;
 @end
 
 @implementation MYTestModel
 @end
 
 MYTestModel *model = [[MYTestModel alloc]initWithDataDic:@{@"name":@"json",@"userId":234}];
