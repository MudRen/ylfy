//����ɽ�ɡ�mhxy-yushu 2001/2
inherit ROOM;
#include <ansi.h>
void create ()
{
	set ("short","��С·");
	set ("long", @LONG

������ʦ�������һ��С·, С·������ʯ�̳ɵأ���ɨ��
��Ϊ�ɾ�����������е��ǳ�ƽ̹��С·�������ǵ�����
LONG);

	set("exits", ([     
       "north" : __DIR__"houlang",
       "south" : __DIR__"westway3",
        "west" : __DIR__"danfang",
       ]));

	setup();
}