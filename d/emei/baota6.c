// Room: /d/emei/baota6.c ������ ����6

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "��������");
	set("long", @LONG
�����Ǵ��������㣬�������ź���ʯ�壬�˽��ε�ǽ������������
ľ�������注����������ȥ���Կ�������ï�ܵ������ż����ֻ�����ӹ���
�ַ����˱�������ա�ת���ȥ�����Կ���ǽ��(wall)�Ͽ��д�εľ��ġ�
���Ͽ�ȥ��Բ�еĶ��ǣ��Ϲ���һ�ڹ��ӡ�
LONG
         );

	set("exits", ([
		"down" : __DIR__"baota5",
	]));
        set("item_desc", ([
           "wall" : @WALL
��˷𾭵�����
���ԡ���������֮λ�����϶�����ӽ���֮������������������֮������ֲ���
�Ӵ�ǧ�硣��һڭ�ӡ��Ӱ����ˮ����Ϳ���͡��ӷ����š��绯���ۡ������ϳˡ�
���ν𲯡��ӷ��������ǰ���������������������������̡�����Ϧ廡��ӵ�����
�������衣��ƽ�ȡ���һ��ء����˻�������ʱľ��
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

   if ( me->query("shen") < (me->query_skill("yugalism",1))* 60)
        return notify_fail("�ҷ�ȱ�������ȥ����ϰ�����书Ҫ���㹻�����С�\n");

   if ( me->query("combat_exp") < (me->query_skill("yugalism",1))* 120)
        return notify_fail("��ľ��鲻�㣡�ȶ��ĥ��ĥ���ɡ�\n");

    message_vision("$N��ʼ������Ķ���ǽ���ϵľ��ġ�\n", me);
 
    if ( me->query_skill("yugalism",1) < 100 )
    {
       return notify_fail("�������ڵ���Ϊ�����޷����ö�ǽ���ϵľ��ģ�\n");
    }
    else if ( me->query_skill("yugalism",1) > 120 )
     {
          return notify_fail("ǽ���ϵľ��Ķ�����˵̫ǳ�ˣ�\n");
     }

    if ( me->query("jing") < 25)
       return notify_fail("���Ѿ����ľ�ƣ���ߣ���Ҫ��Ϣһ���ˣ�\n");


    if (!(myfam = me->query("family")) || myfam["family_name"] == "������"  &&  (string)me->query("class")=="bonze" )
     {
          me->add("jing",-24); 
          me->improve_skill("yugalism", random(me->query_int()));
          return 1;
      }
   else {
        return notify_fail("����˰��죬����ͷ��������һƬ���ң�\n");
        }
}

