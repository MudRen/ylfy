//mishi by suimeng 2015.3
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short","����");
  set ("long", @LONG
       ������������ɵ�һ�������۵�С���䣬��ֻ���������ǽ������
	   �ܶ���ֵĺۼ������߽�һ�������ƺ���ĳ�ֵ�������ɵģ�������
	   �����ɵ��أ���������о�(yanjiu)�¡�
LONG);
  
   set("exits", ([      
       "south" : "d/xuantian/lian",
   ]));
  setup();
}

void init()
{
  add_action("do_yanjiu", "yanjiu");
}

int do_yanjiu(string arg)
{
  object me=this_player();
  int ap;
  
 
  string *poem = ({
		"������ۣ��ƺ��ǡ�"HIM"��������"NOR"����Ϊʲô������ô��������",
		"������ۣ��ƺ������е�������һ�С�"HIG"����һ��"NOR"������ɵģ��ƺ�����Щ��ͬ��",
		"������ۣ���"HIB"����걩"NOR"��Ϊʲô.....�����ѵ���Ϊĳ���ڹ�������������",
		"������ۡ�"HIY"���΢��"NOR"���������������������˿���....",
		"��"HIB"����ֱ׹"NOR"��ô���������ƺ�����Щ��ͬ��Ϊʲô��",
		});

    if(me->is_busy() )
          return notify_fail("������æ���أ����й���ǽ�ϵĶ���...\n");

    if((int)me->query_skill("literate",1) < 5000 )
               return notify_fail("�㿴��ǽ�ϵĵ��ۣ�һ��ãȻ��ʼ���޷�����\n");
   
     ap = me->query_skill("literate", 1) /1000;
   
    if(me->query("family/family_name") != "������")
        {
        tell_object(me,"�㿴��ǽ�ϵĵ��ۣ�����ʲô������ɵģ�����������\n"); 
		return 1;
		}		
	if (me->query("family/master_id")!="wuming laoren")
        {
        tell_object(me,"�㿴��ǽ�ϵĵ��ۣ����ƺ���ĳλ�������������µģ�������˭�أ�����\n"); 
        return 1;
        }
	if (me->query_skill("yijing-force",1) < 1500)
        {
        tell_object(me,"�ƺ�......�ڹ�......Ҳ��.......\n"); 
        return 1;
        }
    if(me->query("jing") < 1000)
        {
        tell_object(me,"�㻹������Ϣһ����ɡ�\n");     
        return 1;
        }
        message_vision("$N��ϸ���о���ǽ�ϵĵ��ۣ�" + poem[random(sizeof(poem))] + "\n", me);
        me->add("jing",-100);		
        me->start_busy(2);
    if(me->query("zjb_dj/dj") >= 25) 
        {
        tell_object(me,"���Ѿ���ȫ���������е����ľ��裬����Ҫ���������ˡ�\n");       
        return 1;
        }
    if((int)me->query_skill("tianxin-blade", 1) > 4000)
		{
        tell_object(me,HIW"����ϸ�о�������ǽ���ϵĵ��ۣ���������ϰ����......\n"NOR);
        me->improve_skill("literate", 50+random(10));
		
        me->start_busy(2);
        }
    if( random(500000) < me->query("kar") + ap && me->query("zjb_dj/dj") < 25)
        {
        me->add("zjb_dj/dj",1);
        tell_object(me,HIG"��ͻȻ�������"HIY"ԭ�����е��������д˵�����"HIR"��\n"NOR);
		tell_object(me,HIG"������е����ľ�����������\n"NOR);
        }
        return 1;
}             

