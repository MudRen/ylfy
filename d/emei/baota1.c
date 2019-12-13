// Room: /d/emei/baota1.c ������ ����1


#include <room.h>
inherit ROOM;
void create()
{
	set("short", "����һ��");
	set("long", @LONG
�����Ǵ����ĵײ㣬���������ǽ�ϵ�С������͸�������������
��ש�������¼����Ӱ����㱼����Կ���ǽ��(wall)�Ͽ��Ŵ�εľ��ġ���
�Ͽ�ȥ��������ľ¥�����ƶ��ϣ��ƺ����޾�ͷ��ǽ�ǣ��ݼ����൱�ྻ��
�����������˴�ɨ��
LONG
         );

	set("exits", ([
		"out" : __DIR__"dabeita",
                "up" : __DIR__"baota2",
	]));
        set("item_desc", ([
           "wall" : @WALL
��˷𾭵�һ��
����ɵ��ѡ�����˼Ω�������ž�������Ϊʤ��ס������������ħ����
�¹ҰԷ�С�ת���з��֡�����ֹ�������뷡�һһ���򡣺��ƾ�ŵ��
��˳��뷡�....
WALL
             ])) ;

        setup();
}
void init()
{
        add_action("do_yuedu", "yuedu");
}

int do_yuedu(string arg)
{

    mapping myfam;
    object me = this_player();
    myfam = me->query("family");
    if ( !arg || (arg != "wall"))
       return notify_fail("��Ҫ�Ķ�ʲô��\n");

    if (me->is_busy())
	return notify_fail("��������æ���ء�\n");

    if ( me->query("shen") < (me->query_skill("yugalism",1))* 10)
        return notify_fail("�ҷ�ȱ�������ȥ����ϰ�����书Ҫ���㹻�����С�\n");

   if ( me->query("combat_exp") < (me->query_skill("yugalism",1))* 20)
        return notify_fail("��ľ��鲻�㣡�ȶ��ĥ��ĥ���ɡ�\n");

    message_vision("$N��ʼ������Ķ���ǽ���ϵľ��ġ�\n", me);

    if ( me->query_skill("yugalism",1) > 20 )
       return notify_fail("ǽ���ϵľ��Ķ�����˵̫ǳ�ˣ�\n");

   if ( me->query("jing") < 10)
       return notify_fail("���Ѿ����ľ�ƣ���ߣ���Ҫ��Ϣһ���ˣ�\n");


   if ( myfam["family_name"] == "������"  &&  (string)me->query("class")=="bonze" )
     {
          me->add("jing",-10); 
          me->improve_skill("yugalism", random(me->query_int()));
          return 1;
      }
   else {
        return notify_fail("����˰��죬����ͷ��������һƬ���ң�\n");
        }
}

