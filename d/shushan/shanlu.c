//����ɽ�ɡ�mhxy-yushu 2001/2
inherit ROOM;
void create ()
{
  set ("short","ɽ´");
  set ("long", @LONG

���۵�С·��ͷ��Ȼ����,���Ϸ��������������ü���ˡ����ںܾ�û
���߶���·�ߵ�С�ݶ�������ô����,��֪����������û��ʲô������
LONG);

  set("outdoors", 2);
  set("exits", ([      
// "southeast" : __DIR__"womeifeng",
 "northeast" : __DIR__"road0",
 "southwest" : __DIR__"shanlu1",

 ]));
 setup();
}





