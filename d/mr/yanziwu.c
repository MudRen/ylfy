#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","������");
         set ("long",@long
��������Ļ��������֮��, Ļ������Ϧ�մ�����ĺ���, �����ռ�ʽ΢, 
�������ȴһ��һ����⸴���ࡣ���书�������Ա�֮��, ��ʩ����, �˵�
ʮ��������
long);
         set("exits",([
	"south" : __DIR__"xiaojing1-2",
	"west" : __DIR__"houyuan1",
             "east" : __DIR__"wuchang",
]));
         setup();
         replace_program(ROOM);
}
