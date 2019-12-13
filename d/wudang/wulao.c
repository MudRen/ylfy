// tyroad6.c ���ɽ·
// by Marz 
inherit ROOM;
#include "feng.h"
string* npcs = ({
        "tufei2",
        "guest",
        "xiao_tufei",
        "guest",
        "xiao_louluo",
        "guest",
});
void create()
{
    int i = random(sizeof(npcs));
    set("short", "���Ϸ�");
    set("long", @LONG
���������Ϸ��ɽ·�ϣ�һ�����ͱڣ�һ�������¡��߸ߵ�������(feng)
�����������У���Լ�ɼ����������ԵĽ���ͺ����˶���ϸ������Լ��Ľ��£�
����̧ͷ��һ�ۣ�Ω��һ��С��ˤ��ȥ������ǿ�˳û���٣������޲�������
����ֻ�����·��
LONG
    );
    set("outdoors", "wudang");
    set("exits", ([
        "northup" : __DIR__"hutou",
        "southdown" : __DIR__"sanlao",
    ]));
    set("item_desc", ([
        "feng" : (:look_feng:),
    ]));
    set("objects", ([
    __DIR__"npc/"+npcs[i] : 2,
    CLASS_D("wudang") + "/yin" : 1, 
    ]));
    setup();
}
void init()
{
        add_action("look_feng", "look");
}
