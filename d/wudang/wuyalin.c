// tyroad4.c ���ɽ·
// by Marz 
inherit ROOM;
#include "feng.h"
string* npcs = ({
        "guest",
        "tufei2",
        "guest",
        "xiao_tufei",
        "guest",
        "xiao_louluo",
});
void create()
{
    int i = random(sizeof(npcs));
    set("short", "��ѻ��");
    set("long", @LONG
�����䵱����ѻ�룬��ǰ��һƬ����ڣ�ɽ·���������һ�����ͱڣ�һ��
�����¡��߸ߵ�������(feng)�����������У���Լ�ɼ����������ԵĽ���ͺ���
�˶���ϸ������Լ��Ľ��£�����̧ͷ��һ�ۣ�Ω��һ��С��ˤ��ȥ������ǿ��
�û���٣������޲�����������ֻ�����·��
LONG
    );
    set("outdoors", "wudang");
    set("exits", ([
        "northup" : __DIR__"sanlao",
        "southdown" : __DIR__"nanyan",
    ]));
    set("item_desc", ([
        "feng" : (:look_feng:),
    ]));
    
    set("objects", ([
    __DIR__"npc/"+npcs[i] : 1]));
                                    
    setup();
}
void init()
{
        add_action("look_feng", "look");
}
