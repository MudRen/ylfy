// Room: /d/emei/shanpo.c ɽ��
// create by host dec,20 1997

inherit ROOM;
void init();

void create()
{
        set("short", "ɽ��");
	set("long", @LONG
��������Ů����һ�����£����������ȥ��ֻ����������ʱ�����·���
Ʈ�����������ˡ����������澰ɫ����һ�䣬ɽ���������˸�ɫ�Ļ��ݣ�ÿ��
�峿����������ˮ��ʪ�Ļ��꣬�ڳ�ϼ��ӳ�����Եĸ����������Ŀ������
���������Ե�ʯ�����Ӳݴ�����������Լ���Կ���ʯ���󷽰��ݴ���һ������
LONG
	);
        set("exits", ([
           "down":  __DIR__"milin3",
	]));
	setup();
}
int valid_leave(object me, string dir)
{
    int i;
    object *inv,room;
    mapping myfam;
    myfam = me->query("family");
    room = load_object(__DIR__"shandong14");
    inv = all_inventory(this_player());
     for(i=sizeof(inv)-1; i>=0; i--) {
    if( inv[i]->is_character() && dir == "west")
       return notify_fail("����ֻ����һ����ͨ�����������ǹ���ȥ�ġ�\n");
     }
   if ( (!(myfam = me->query("family"))) &&  dir == "down")
       return ::valid_leave(me,dir);
   if ( (!(myfam = me->query("family"))) || (myfam["master_name"] != "������") && dir=="west")
     {
                remove_call_out("close_gate");
     if(objectp(room))
      {
        delete("exits/west");
        message("vision", "ֻ�����һ�����죬ʯ���ִ��º���������\n",
            this_object());
        room->delete("exits/east");
        if (objectp(room))
           message("vision", "ֻ�����һ�����죬ʯ���ִ��º���������\n", room);
     }
      return notify_fail("");
    }
    return ::valid_leave(me,dir);
   
}

void init()
{
    add_action("do_pull", "pull");
}

int close_gate()
{
    object room;
    if(!( room = find_object(__DIR__"shandong14")) )
        room = load_object(__DIR__"shandong14");

    if(objectp(room))
    {
        delete("exits/west");
        message("vision", "ֻ�����һ�����죬ʯ���ִ��º���������\n",
            this_object());
        room->delete("exits/east");
        if (objectp(room))
           message("vision", "ֻ�����һ�����죬ʯ���ִ��º���������\n", room);
     }
}

int do_pull(string arg)
{
    object room;

    if (query("exits/west"))
        return notify_fail("ʯ���Ѿ��ǿ����ˡ�\n");

    if (!arg || (arg != "tiehuan"))
        return notify_fail("��Ҫ��ʲô��\n");

    if(!( room = find_object(__DIR__"shandong14")) )
        room = load_object(__DIR__"shandong14");
    
    if(objectp(room))
    {
        set("exits/west",__DIR__"shandong14");
        message_vision("$N�þ���������һ��������"
            "ֻ��֨֨�������죬��ʯ��ǰ������һ�����ڡ�\n",this_player());
        room->set("exits/east", __FILE__);
        message("vision", "����ǰ��ʯ�ڴ����˼������죬֨ѽѽ�ı��˴��ˡ�\n", room);
        remove_call_out("close_gate");
        call_out("close_gate", 10);
    }

    return 1;
}
