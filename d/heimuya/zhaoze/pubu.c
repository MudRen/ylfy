
inherit ROOM;
void create()
{
        set("short", "����ɽ��");
        set("long", @LONG
������ˮ�����������¡¡�����糱ˮ����һ�㣬̧ͷһ����ֻ��
���������������ӵ�����һ�����ٲ��Ӹ�����ֱк������ֻ���������
��������أ�Բ�����ͷ��
LONG
);
        set("outdoors", "pubu");
        set("exits", ([
  "southdown" : __DIR__"xiaodao",
  "westdown" : __DIR__"lczb",
  "northup" : __DIR__"lingding",
]));

        setup();
}

void init()
{
     object me;
     me = this_player();
     if( random((int)me->query_kar()) > 20 ){
     call_out("close_door",10,me);
     }
}

void close_door(object me)
{
        object room;
        if (!me || environment(me)!=this_object()) return;
        room=find_object(__DIR__"xiaoyao/pubu");
        if (!room)
        room = load_object(__DIR__"xiaoyao/pubu");
        message_vision("ͻȻ$N����̤�˸��գ����ӵ�ʱ������ȥ��\n",me);
        me->move(__DIR__"xiaoyao/pubu");
        message_vision("�飡$N����������\n",me);
}
