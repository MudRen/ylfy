// sanqingdian.c �����

#include <ansi.h> 
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
��������������������ȫ��̻�͵ĵص㡣���й���Ԫʼ�����鱦��
���̫���Ͼ��������㰸���������ơ���ǽ���ż���̫ʦ�Σ����Ϸ��ż�����
�š��ϱ�����ʵ�����Ǻ�
LONG
        );
        set("valid_startroom", 1);
        set("exits", ([
                "south" : __DIR__"yuhuangdian",
                "west" : __DIR__"xilang1",
                "east" : __DIR__"donglang1",
                "north" : __DIR__"houdian",
        ]));

       set("objects", ([
            "/d/quanzhen/npc/yinzhiping" : 1]));

       
        setup();
        "/clone/board/quanzhen_b"->foo();
//        replace_program(ROOM);
        
}
/*
void init()
{
        object me;
        mapping skill_status;
        string *sname;
        int i, level; 
        float exper;

        me = this_player();

        exper = to_float(me->query("combat_exp"));

        if ( !(skill_status = me->query_skills()) ) return;
        sname  = keys(skill_status);

        for(i=0; i<sizeof(skill_status); i++) 
        {
                level = skill_status[sname[i]];
                if( pow(to_float(level), 3.0) / 10.0 > exper 
                && exper > 100.0
                && sname[i] != "buddhism"
                && sname[i] != "literate"
                && sname[i] != "taoism" ) 
                {
                        level = ceil( pow( exper*10.0, 0.333333) );
                        me->set_skill(sname[i], level);
                }
        }
}
*/

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "ȫ���") && dir == "north" &&                 objectp(present("master yin", environment(me))))
     return notify_fail(HIW"\n ��־ƽ�ȵ����㲻��ȫ����ӣ�Ҫ���ȥ��ʤ�������г���! \n\n"NOR);
                
        return ::valid_leave(me, dir);
}

