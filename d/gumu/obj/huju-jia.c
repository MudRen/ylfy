#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIW "���߼�" NOR, ({ "huju jia", "jia" }) );         
        set_weight(30000000);
        if( clonep() )
                set_default_object(__FILE__);
        else{
        set("unit", "��");
        set("long", "һ��ľͷ�Ƴɵļ��ӣ������������(armor)�Ȼ��ߡ�\n
�����ʽ: na armor from jia��\n");
        set("material","wood");
        set("no_get",1);
        }
        setup();
}

void init()
{
       add_action("do_get","na");
}

int do_get(string arg)
{
      object me,ob;
      string arg1,arg2;
      me=this_player();
      if(!arg || sscanf(arg, "%s from %s", arg1, arg2)!=2)
          return notify_fail("�����ʽ: na <��������> from jia��\n");
      if (arg2!="jia")
          return notify_fail("�����ʽ: na <��������> from jia��\n");
      if(me->query_temp("marks/��"))
          return notify_fail("����ô��ô̰�ģ��ù��˻�Ҫ�ã�\n");
      if(me->query("combat_exp") > 120000)
          return notify_fail("�������ѵ�һ���̶ȣ�������ʳ�����ɡ�\n");
      if (arg1 =="armor"){
           ob=new("/d/city/obj/tiejia"); 
          ob->move(me);
          message_vision("$N�ӻ��߼����ó�һ��$n��\n",me, ob); 
          me->set_temp("marks/��",1);
          return 1;
          }     
     return notify_fail("���߼���û������Ҫ�õĶ�����\n");
}

