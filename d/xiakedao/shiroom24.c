// /d/xiakedao/shishi24.c ���͵� ʯ��24

inherit ROOM;

int do_study(string arg);
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
������谵��ֻ������������ľ������ϥ���ڽ���֮�ϣ����
ʯ��(wall)�������˼����ʯ������ɽ�������ȴ�����ߴ����
���½����ˡ����л�������������Ķ�����֮�ࡣ
LONG );
        set("exits", ([
                "east" : __DIR__"shihole6",
        ]));
        set("item_desc", ([
                "wall" : @WALL
ǽ�����Ϸ����š�����̫�������������֡��ֵ��·��̵�����������
������ģ���ǧ�������������������룬����������ֱ��б����
�µĴ�Ƭ�������һ���ѷִ���ίʵ���Ա��ϣ�canwu����
WALL
        ]));
        set("objects", ([
                 __DIR__"npc/mu" : 1,
                __DIR__"npc/long" : 1,
        ]));
        set("no_clean_up", 0);
       //  set("no_fight", 1);
        set("no_beg", 1);
        setup();
}

void init()
{
        add_action("do_study","think");
		add_action("do_canwu","canwu");
}
#include "/d/xiakedao/shiroom.h"

int do_canwu(string arg)
{
  object me=this_player();
  int ap;
  
 
  /*string *poem = ({
		"��ͽ֪����Ϣ˼Ϊ����֮�����ⲻ֪�ϴ�֮ʿ��Բͨ���ۣ�����˫�ޣ���������������������",
		"��֮���������Ŷ������㣬�ǹ���ʤʵ������ʤ���š����ⲩ������£���Ȥ����֮��֣�����֮���ң��仯֮�ɱ�����֮���¡�",
		"��֮ʤǿ����֮ʤ�գ�����Ī��֪��Ī���С�",
		"����֮���ᣬ�۳�����֮���ᡣ",
		"��ָ�������޼᲻�ƣ��ݵ����ԣ��紩������",
		"���������������Ծš�̫�������ǣ���س����С������Ѽ������߹�Ԫ̫�أ�̫��������£���֮�崿����֮ԨԴ��",
		});*/

    if(me->is_busy() )
          return notify_fail("������æ���أ����й���ǽ�ϵĶ���...\n");

    if((int)me->query_skill("literate",1) > 0 )
               return notify_fail("�㿴��ǽ�ϵ�����ģ�һ��ãȻ��ʼ���޷�����\n");
   
     ap = me->query_skill("taixuan-gong", 1) /1000;
   	
    if(me->query("jing") < 1000)
        {
        tell_object(me,"�㻹������Ϣһ����ɡ�\n");     
        return 1;
        }	
    if(me->query("potential") < 1000)
        {
        tell_object(me,"���Ǳ�ܲ���.....��\n");     
        return 1;
        }	
        
        me->add("jing",-100);
		me->add("potential",-100);
        me->start_busy(2);
       if(me->query("taixuan/jm")) 
        {
        tell_object(me,"���Ѿ���ȫ������̫�����ľ��裬����Ҫ���������ˡ�\n");       
        return 1;
        }
    if((int)me->query_skill("taixuan-gong", 1) > 2000)
		{
        tell_object(me,HIW"����ϸ�о�������ǽ���ϵ����֣���������ϰ����......\n"NOR);
        me->improve_skill("literate", 50+random(10));
		
        me->start_busy(2);
        }
    if( random(2000000) < me->query("kar") + ap )
        {
        me->add("taixuan/jm",1);
		tell_object(me,HIG"���Ѿ�����̫�����ľ���\n"NOR);
        }
        return 1;
}             