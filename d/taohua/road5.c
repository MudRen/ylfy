inherit ROOM;
 
void create()
{
        set("short", "����");
        set("long",@LONG
  ����һ����ɽ�ϵ�һ��Сɽ�������ں�С��������һ�������ȥ������������
  ʲôҲ��������
LONG);
        set("exits", ([
  "west"   : __DIR__"road4",
  "enter"  : __DIR__"dong",
]));
        set("outdoors", "taohua");
 
        setup();
}
