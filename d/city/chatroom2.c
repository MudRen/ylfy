// Room: /d/snow/chatroom.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
��ô������治��Ϊǧ����ľ�������Ͼ��ɸ��ϼ������ӣ������ǵڶ��㣬��
˵�����ʱ��Ҳ�Ƕ���ģ����һЩ��������̫������Ҳ������������һ���徲��
������ż������������������ӣ��м��ü�������֦����һ������һ���輸�ˡ�
����̧ͷ���Ͽ���ʱ���ƺ��и�Ӱ������֮���ƶ�������Ҳ���Ƿ紵������ɵ�
�����
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([
        "down": __DIR__"chatroom",
        "up"  : __DIR__"tianti",
        ]));
        set("no_fight",1);
        set("no_magic",1);
      set("valid_startroom","1");
        set("freeze",1);
        set("objects", ([
        ]));
        setup();
        call_other("/clone/board/comm_b", "???");
}
void init()
{
    if (wizardp(this_player())) return;
    add_action("do_jump","tiao");
    add_action("discmds",({"sleep","respitate","exert","array","duanlian","ansuan","touxi","persuade","teach","exert","exercise","study","learn","kill","steal","conjure","fight","hit","perform","prcatice","scribe","surrender"}));
    add_action("do_climb", "climb");
}
int discmds()
{
        tell_object(this_player(),"�����㻹��ר������ɣ�\n");
        return 1;
}
int do_climb(string arg)
{
    object me;
    me=this_player();
        if( !arg || arg!="down") return notify_fail("��Ҫ���ĸ���������\n");

    if (me->query("gender")!="Ů��")
    message("vision",
        me->name() + "���������ץס���ɣ�ƨ��һŤһŤ��������ȥ��\n",
        environment(me), ({me}) );
   else if(me->query("age")<40&&me->query("per")>24)
    message("vision",
        me->name() + "�����Ӱ��������Ʈȥ��ת˲���š�\n",
        environment(me), ({me}) );
   else message("vision",
        me->name() + "սս������ץס����������ȥ��\n",    environment(me), ({me}) );
     me->move(__DIR__"chatroom");
     
     if (me->query("gender")!="Ů��")
        message("vision",
        me->name() + "��������ش���������������\n",
                environment(me), ({me}) );
 else if(me->query("age")<40&&me->query("per")>24)
        message("vision","һ������������㶨��һ����"+
        me->name() + "�Ѿ���������������ǰ��\n",
        environment(me), ({me}) );   
          
   else 
        message("vision", me->name() + "սս�����ش���������������\n", environment(me), ({me}) );   
        
    
    return 1;
}   
int valid_leave(object me, string dir)
{
//           if (dir=="up"){	
if (dir=="hereup"){	
if (wizardp(me)) return 1;
else    return notify_fail("����ô�ߣ� С�ĵ�����ˤ��!\n");
        }
         if ( dir=="down" && !wizardp(me))
        return notify_fail("����û��ֱ���ߣ�������ֻ����(climb)��ȥ��\n");

        else return 1;
}
