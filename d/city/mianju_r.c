// Room: /u/wyz/mianju1.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
        set("short", "Ϧ�����");
        set("long", @LONG
������һ�ҳ����ģ�����Ĵ������������ͥ���У��ò����֣���̨���Ư
��С�㿴���������Ц�����ӭ��������ʹ�˻�û���������������һ���ֲ�˼
��ĸо���������������ֻ����ͷ���������Ѿ����Ͳ�ס�����˽�ȥ
LONG
);
        set("exits", ([
                "southeast" : "/d/city/guangchang",      	
        ]));
           set("objects", ([ /* sizeof() == 1 */
                __DIR__"obj/guizi" : 1,
           ]));

    set("no_fight",1);  
     setup();	
    call_other("/clone/board/mianju_b", "???");
		
}
void init()
{
        object me=this_player();
        add_action("kick_out","kickout");
        if (me->query("id")!="zjkknds")
        if (me->name()!=me->name(1)){
         message_vision("$N�Ӱ���л���һ������Ļ��ߣ��Һ��ŷ��˳�ȥ ��\n",me);
         me->move("/d/city/guangchang");
        }
        add_action("discmds",({"pretend","kill","hit","array"}));
}
int discmds(string arg)
{
    tell_object(this_player(),"�̳�����ɲ��ܶ���Ү��\n");
    return 1;
}

int kick_out(string str)
{
   object me=this_player();
   object ob;
   if (!str) return 0;
   if (me->query("id")!="zjkknds") return 0;
   if (!ob=present(str,this_object()))
        return 0;
   if (!living(ob) || wizardp(ob))      return 0;
   message_vision("$N������Ű�$n�����������������ҽŰ�$n���˳�ȥ��\n",me,ob);
   ob->move("/d/city/guangchang");
   message("vison",ob->name()+"�Ӱ���л���һ������Ļ��ߣ��Һ��Ź�����űߣ�\n",environment(ob),({ob}));
   return 1;
}

