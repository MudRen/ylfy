//make by yixiang
#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short", "ҩ������");
        set("long", @LONG
����ҩ�̵����ң�������÷�ҩ(fengyao)�������ҩ���ϰ����
��ҩ���������Ӿ��� Ǳ��ѽ ��
LONG
        );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);

        set("exits", ([
                "south" : __DIR__"yaopu",
                
]));
        setup();
}
void init()
{
        add_action("do_fengyao","fengyao");
        add_action("do_ban","dazuo");
        add_action("do_ban","tuna");
        add_action("do_ban","du");
        add_action("do_ban","study");
        add_action("do_ban","exercise");

}

int do_ban()
{
        write ("���ʲô���Ǳ��˵�����ѽ����ҪӰ����˹�����\n");
        return 1;
}
int do_fengyao()
{
        object me = this_player();
        int bonus,exp,pot;
        object mon;
        if((int)me->query_temp("fengyaoover"))
              return notify_fail("���ҩ�Ѿ������ˣ���ȥ���ϰ�Ҫ����ɡ�\n");        
        if( (int)me->query_temp("fengyao") ) 
              return notify_fail("���Ѿ��ڹ����ˡ�\n");
       if (!(int)(me->query_temp("fengyaobegin")))
              return notify_fail("������ʲô���߿��ߡ�\n");
        message_vision("
$N������һ�壬����һ��Ҫ���һ�������ӣ������ָ�ҩҲҪ��ô����\n\n",me);
        me->set_temp("fengyao",1);
        me->add("qi",-5);
        me->delete_temp("fengyaobegin");
        call_out("del_fengyao", 1, me, mon, bonus, exp, pot);
        return 1;
}
void del_fengyao(object me, object mon, int bonus, int exp, int pot)
{
       int xunhuan;
       xunhuan=random(4);
       xunhuan+=2;
       me->delete_temp("fengyao");
       while(xunhuan > 0) {
       
          if (random (8) <1) {
              message_vision(HIY"��ѽ��$N�۵���ͷ�󺹣�һ��С�ķִ���ҩ��\n"NOR,me);
              me->add("qi",-5);
               me->start_busy(1);
              me->set_temp("fengyaow",1);
              }
             else {
               switch(random(3)) {
               case 0: 
                 { message_vision("ֻ��$N����һ�ӣ�ҩ��Ȼ�պ��ӽ�ҩ�䣬������ѽ��\n",me); 
me->add("qi",-1); 
me->start_busy(1);	}
break;
               case 1: 
                 { message_vision("$N�ֵĺ���ϸѽ����Ҫ���һ�Ρ�\n",me);
me->add("qi",-3); 	
me->start_busy(3);}
                  break;
               case 2: 
                 { message_vision("$N�������ϵ�ҩ�ģ����˰������ڻ���û���ҵ��÷ŵĵط���\n",me); 
me->add("qi",-4); 	
me->start_busy(4);}
                  break;
                }
                me->start_busy(1);
              }
              xunhuan--;
             } 
write(HIW"\n ��������ˣ��������ˣ��������ڿ���ȥ��Ϣһ����.\n�����һ�Ҫȥ�ñ����أ��ɲ��ܰ׸ɡ�\n"NOR);
     me->set_temp("fengyaoover",1);
     return ;
}
        
