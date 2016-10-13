用法:
继承MYBaseModel
一般命名只要不是id,均可以自动转换成模型

@interface MYTestModel :MYBaseModel <NSCoding, NSCopying>
 @property (nonatomic, copy) NSString *name;
 @property (nonatomic, copy) NSString *userId;
 @end
 
 @implementation MYTestModel
 @end
 
 MYTestModel *model = [[MYTestModel alloc]initWithDataDic:@{@"name":@"json",@"userId":234}];
