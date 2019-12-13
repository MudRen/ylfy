// Room: /d/emei/baota3.c ������ ����3

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "��������");
	set("long", @LONG
�����Ǵ��������㣬�������ź���ʯ�壬�˽��ε�ǽ������������
ľ�������Ĺر��ţ����������������һյС�����ƣ�����������ǽ�ں���
��������㱼��ֿɿ���ǽ��(wall)�Ͽ��д�εľ��ġ����Ͽ�ȥ��������ľ
¥�����ƶ��ϣ��ƺ����޾�ͷ��
LONG
         );

	set("exits", ([
		"down" : __DIR__"baota2",
                "up" : __DIR__"baota4",
	]));
        set("item_desc", ([
           "wall" : @WALL
��˷𾭵�����
���ԡ��󻳰������������ߡ�Ʃ���ˮ�����ֽ�֮�����˹��١����ж���Ӱ�ߡ�
���԰��������������ˡ��ʲ����������ɳ�š����ᰮ������������������
���ӡ�....
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

   if ( me->query("shen") < (me->query_skill("yugalism",1))* 30)
        return notify_fail("�ҷ�ȱ�������ȥ����ϰ�����书Ҫ���㹻�����С�\n");

   if ( me->query("combat_exp") < (me->query_skill("yugalism",1))* 60)
        return notify_fail("��ľ��鲻�㣡�ȶ��ĥ��ĥ���ɡ�\n");

    message_vision("$N��ʼ������Ķ���ǽ���ϵľ��ġ�\n", me);

     if ( me->query_skill("yugalism",1) < 40 )
    {
       return notify_fail("�������ڵ���Ϊ�����޷����ö�ǽ���ϵľ��ģ�\n");
    }
    else if ( me->query_skill("yugalism",1) > 60 )
     {
          return notify_fail("ǽ���ϵľ��Ķ�����˵̫ǳ�ˣ�\n");
     }

    if ( me->query("jing") < 15)
       return notify_fail("���Ѿ����ľ�ƣ���ߣ���Ҫ��Ϣһ���ˣ�\n");


    if (!(myfam = me->query("family")) || myfam["family_name"] == "������"  &&  (string)me->query("class")=="bonze" )
     {
          me->add("jing",-16); 
          me->improve_skill("yugalism", random(me->query_int()));
          return 1;
      }
   else {
        return notify_fail("����˰��죬����ͷ��������һƬ���ң�\n");
        }
}

