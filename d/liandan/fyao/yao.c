// By zjb@ty
// 这分code 介绍的比较详细,准备给天涯新手巫师学习用的

inherit ITEM; 
mapping *ansi= ({
([     "yanse":    HIC,]),
([     "yanse":    HIG,]),
([     "yanse":    HIR,]),
([     "yanse":    HIB,]),
([     "yanse":    HIM,]),
([     "yanse":    HIY,]),
([     "yanse":    RED,]),
([     "yanse":    YEL,]), 
([     "yanse":    MAG,]),
([     "yanse":    CYN,]),

});
mapping *yao= ({
([     "name":     "丹参",
       "id":       "dan shen",
       "shoubi":   1,   
       "random":   10,
       "tui":      21,]),
([     "name":     "地鳖虫",
       "id":       "dibie chong",
       "shoubi":   2,  
       "tui":   29,  
       "random":   11,
       "all":      11,]),
([     "name":     "自然铜",
       "id":       "ziran tong",
       "shoubi":   3, 
       "random":   12,
       "all":      12,
       "tui":      22,]),
([     "name":     "骨碎补",
       "id":       "gusui bu",
       "shoubi":   4, 
       "all":      13,
       "random":   13,
       "tui":      23,]),
([     "name":     "冰片",
       "id":       "bing pian",
       "shoubi":   5, 
       "random":   14,
       "all":      14,]),
([     "name":     "血竭",
       "id":       "xue xie",
       "shoubi":   6, 
       "all":      15,
       "random":   15,
       "tui":      24,]),
([     "name":     "龙骨",
       "id":       "long gu",
       "shoubi":   7, 
       "all":      16,
       "random":   16,
       "tui":      25,]), 
([     "name":     "没药",
       "id":       "yao",
       "shoubi":   8, 
       "all":      17,
       "random":   17, 
       "tui":      26,]),
([     "name":     "红花",
       "id":       "hong hua",
       "shoubi":   9, 
       "all":      18,
       "random":   18,
       "tui":      27,]),
([     "name":     "白芷",
       "id":       "bai zhi",
       "random":   19,
       "shoubi":   10,
]),
([     "name":     "三七",
       "id":       "san qi",
       "shoubi":   11,   
       "tui":   28,   
       "random":   20,
       "all":   19,   
]),
});
void create()
{
    string name,id;
    int shoubi,tui,all,yaoo,yanse,all2;

    yanse = random(sizeof(ansi));
// 随机抽出*ansi里的其中一个([])

    yaoo = random(sizeof(yao)); 
// 随机抽出*yao里的其中一个([]) 
    name = yao[yaoo]["name"];
// name做为变量,name= *yao这个mapping里的[yaoo]{也就是上面抽出来的那个}
// 里的name变量名! 
    id = yao[yaoo]["id"]; 
// id做为变量,name= *yao这个mapping里的[yaoo]{也就是上面抽出来的那个}
// 里的id变量名!
// 以下的shou和tui all都是这个原理,不一一介绍了!
    shoubi = yao[yaoo]["shoubi"]; 
    tui = yao[yaoo]["tui"];
    all = yao[yaoo]["all"];
    all2 = yao[yaoo]["random"];
    set_name(ansi[yanse]["yanse"]+name+NOR,({id}) );  
// 设定该object 的name,中文名字为name变量,上面已经定义了
// id名为id变量,上面已经定义了! 
    set_weight(100);
    if( clonep() )
    set_default_object(__FILE__);
    else {
         set("unit", "个");                        
        }

   set("shoubi",shoubi);    
// 设定该obj shoubi变量为,上面以定义的shoubi变量名
// 以下也是这个原理
   set("all",all);
   set("tui",tui);
   set("random",all2);
   set("yao",1);
   setup();
  }


