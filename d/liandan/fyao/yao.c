// By zjb@ty
// ���code ���ܵıȽ���ϸ,׼��������������ʦѧϰ�õ�

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
([     "name":     "����",
       "id":       "dan shen",
       "shoubi":   1,   
       "random":   10,
       "tui":      21,]),
([     "name":     "�ر��",
       "id":       "dibie chong",
       "shoubi":   2,  
       "tui":   29,  
       "random":   11,
       "all":      11,]),
([     "name":     "��Ȼͭ",
       "id":       "ziran tong",
       "shoubi":   3, 
       "random":   12,
       "all":      12,
       "tui":      22,]),
([     "name":     "���鲹",
       "id":       "gusui bu",
       "shoubi":   4, 
       "all":      13,
       "random":   13,
       "tui":      23,]),
([     "name":     "��Ƭ",
       "id":       "bing pian",
       "shoubi":   5, 
       "random":   14,
       "all":      14,]),
([     "name":     "Ѫ��",
       "id":       "xue xie",
       "shoubi":   6, 
       "all":      15,
       "random":   15,
       "tui":      24,]),
([     "name":     "����",
       "id":       "long gu",
       "shoubi":   7, 
       "all":      16,
       "random":   16,
       "tui":      25,]), 
([     "name":     "ûҩ",
       "id":       "yao",
       "shoubi":   8, 
       "all":      17,
       "random":   17, 
       "tui":      26,]),
([     "name":     "�컨",
       "id":       "hong hua",
       "shoubi":   9, 
       "all":      18,
       "random":   18,
       "tui":      27,]),
([     "name":     "����",
       "id":       "bai zhi",
       "random":   19,
       "shoubi":   10,
]),
([     "name":     "����",
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
// ������*ansi�������һ��([])

    yaoo = random(sizeof(yao)); 
// ������*yao�������һ��([]) 
    name = yao[yaoo]["name"];
// name��Ϊ����,name= *yao���mapping���[yaoo]{Ҳ���������������Ǹ�}
// ���name������! 
    id = yao[yaoo]["id"]; 
// id��Ϊ����,name= *yao���mapping���[yaoo]{Ҳ���������������Ǹ�}
// ���id������!
// ���µ�shou��tui all�������ԭ��,��һһ������!
    shoubi = yao[yaoo]["shoubi"]; 
    tui = yao[yaoo]["tui"];
    all = yao[yaoo]["all"];
    all2 = yao[yaoo]["random"];
    set_name(ansi[yanse]["yanse"]+name+NOR,({id}) );  
// �趨��object ��name,��������Ϊname����,�����Ѿ�������
// id��Ϊid����,�����Ѿ�������! 
    set_weight(100);
    if( clonep() )
    set_default_object(__FILE__);
    else {
         set("unit", "��");                        
        }

   set("shoubi",shoubi);    
// �趨��obj shoubi����Ϊ,�����Զ����shoubi������
// ����Ҳ�����ԭ��
   set("all",all);
   set("tui",tui);
   set("random",all2);
   set("yao",1);
   setup();
  }


