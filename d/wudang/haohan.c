// shijie3.c �ú���
// by Xiang
// by arnzh 97/1/23
inherit ROOM;
#include "/clone/item/liuxing.h"
void create()
{
    set("short", "�ú���");
    set("long", @LONG
������һ����ʵ��ʯ���ϣ���ʱ���н���ʹ��������߹���һ������
�ڣ�һ�������£�̧ͷ��Լ�ɼ������������е������壬������ˮ���ȣ���
���Ŀ�������������һ���Ʒ���������һ�ھ���������·����Щ���ھ�����
Ϣ��Щ����ƴ���װˮ��
LONG
    );
        set("outdoors", "wudang");
                     set("resource/water", 1);
    set("exits", ([
            "west": __DIR__"shuijing",       
        "southdown" : __DIR__"shijie32",
        "northup" : __DIR__"shijie42",
    ]));
    setup();
    replace_program(ROOM);
}
