inherit ROOM;
void create()
{
          set("short", "͵�־�");
        set("long", @LONG
͵�־�,ͨ�԰�����֮һ���տյ�ס����͵����ϲ��͵������
����������ڷ�����춼������͵��͵�ǣ��ʹ������ȥ��
�ط���
LONG
        );
        set("exits", ([
                 "south" : __DIR__"jiujv",
                 "west" : __DIR__"fengjv",
        ]));
        set("objects", ([
        "/d/tongchi/npc/touguai":1,
        ]));
        setup();
        replace_program(ROOM);
}
