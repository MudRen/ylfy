#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short","����");
        set("long",@long
���߽����СС������, �����������һ����̴ľ�輸�ͼ�����������
�ӣ���̴ľ�Ĳ輸�ϰڷ��Ų���ͼ�ֻ���񱭣�ר���������á����̲�
ס�����������ϣ���ƣ�������ĵõ���ֵ���Ϣ��
long);
         set("exits",([
             "east" : __DIR__"c14-4",
          "north" : __DIR__"c14-2",
             "west" : __DIR__"yunjinlou",
]));
         set("objects",([
             __DIR__"obj/putao" : 1,
             __DIR__"obj/guiyuan" : 1,
	     __DIR__"obj/xiangcha" : 2,
]));
         setup();
         replace_program(ROOM);
}
