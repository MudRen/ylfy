// Room: disandian.c ������

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
������ȫ��̵ĵ������ȫ�����Ӽ���֮��������а��������ǵķ�
λ�ڷ����������ӡ����������ȣ������Ǻ������Ǻ�Ժ��
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
            "north" : __DIR__"houyuan",
            "south" : __DIR__"houdian",
           ]));
         set("objects",([
"/d/quanzhen/npc/haodatong" : 1]));
               
        setup();
}
int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "ȫ���") &&!wizardp(me) 
	&& dir == "north" &&
		objectp(present("hao datong", environment(me))))
	   return notify_fail("�´�ͨ�ȵ�������Ժ�صأ��㲻��ȫ��̵��ӣ��������ڡ���\n");
		
        return ::valid_leave(me, dir);
}

