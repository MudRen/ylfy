// bye enter 

inherit ROOM;

void create()
{
        set("short", "�͵��¥");
        set("long", @LONG
�������ڿ͵��¥�������ϣ����������ӿͷ��ﲻʱ�غ����Ĵ�����
һ��߹�һ�󡣲�ʱ��˯�����ʵ��ÿͽ�����������¥�µ��ƹ񴦸���Ǯ
������˯����
LONG
        );

        set("exits", ([
                "down" : __DIR__"kedian",
                "1" : __DIR__"kefang1",
                "2" : __DIR__"kefang2",
                "3" : __DIR__"kefang3",
                "4" : __DIR__"kefang4",
                "5" : __DIR__"kefang5",
        ]));
        setup();
}

void init()
{
       this_player()->delete_temp("rent_paid");
}
