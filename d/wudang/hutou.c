// tyroad7.c ���ɽ·
// by Marz 
inherit ROOM;
#include "feng.h"

void create()
{
    set("short", "��ͷ��");
    set("long", @LONG
�����ڻ�ͷ��ɽ·�ϣ�һ�����ͱڣ�һ�������¡��߸ߵ�������(feng)
�����������У���Լ�ɼ����������ԵĽ���ͺ����˶���ϸ������Լ��Ľ�
�£�����̧ͷ��һ�ۣ�Ω��һ��С��ˤ��ȥ������ǿ�˳û���٣������޲�
����������ֻ�����·��
LONG
    );
    set("outdoors", "wudang");
    set("exits", ([
        "north" : __DIR__"chaotian",
        "southdown" : __DIR__"wulao",
    ]));
    set("item_desc", ([
        "feng" : (:look_feng:),
    ]));
    setup();
}
void init()
{
        add_action("look_feng", "look");
}
