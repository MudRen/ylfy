// Room: /d/emei/baota2.c ������ ����2

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "��������");
	set("long", @LONG
�����Ǵ����Ķ��㣬�������ź���ʯ�壬�˽��ε�ǽ������������
ľ�������Ĺر��ţ����������������һյС�����ƣ�����������ǽ�ں���
��������㱼��ֿɿ���ǽ��(wall)�Ͽ��д�εľ��ġ����Ͽ�ȥ��������ľ
¥�����ƶ��ϣ��ƺ����޾�ͷ��
LONG
         );

	set("exits", ([
		"down" : __DIR__"baota1",
                "up" : __DIR__"baota3",
	]));
        set("item_desc", ([
           "wall" : @WALL
��˷𾭵ڶ���
���ԡ����׳��ҡ�ʶ�Ĵﱾ������Ϊ������Իɳ�š����� ������ʮ�䡣
��ֹ�徻��Ϊ������С��ɰ��޺������޺��ߡ��ܷ��б仯������������
ס����ء�....
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
    if ( !arg || (arg != "wall"))
       return notify_fail("��Ҫ�Ķ�ʲô��\n");

    if (me->is_busy())
	return notify_fail("��������æ���ء�\n");

   if ( me->query("shen") < (me->query_skill("yugalism",1))* 20)
        return notify_fail("�ҷ�ȱ�������ȥ����ϰ�����书Ҫ���㹻�����С�\n");

   if ( me->query("combat_exp") < (me->query_skill("yugalism",1))* 40)
        return notify_fail("��ľ��鲻�㣡�ȶ��ĥ��ĥ���ɡ�\n");

    message_vision("$N��ʼ������Ķ���ǽ���ϵľ��ġ�\n", me);

      if ( me->query_skill("yugalism",1) < 20 )
    {
       return notify_fail("�������ڵ���Ϊ�����޷����ö�ǽ���ϵľ��ģ�\n");
    }
    else if ( me->query_skill("yugalism",1) > 40 )
     {
          return notify_fail("ǽ���ϵľ��Ķ�����˵̫ǳ�ˣ�\n");
     }
 
      if ( me->query("jing") < 20)
       return notify_fail("���Ѿ����ľ�ƣ���ߣ���Ҫ��Ϣһ���ˣ�\n");


    if (!(myfam = me->query("family")) || myfam["family_name"] == "������"  &&  (string)me->query("class")=="bonze" )
     {
          me->add("jing",-13); 
          me->improve_skill("yugalism", random(me->query_int()));
          return 1;
      }
   else {
        return notify_fail("����˰��죬����ͷ��������һƬ���ң�\n");
        }
}

