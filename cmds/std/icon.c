#include <ansi.h>
#include <liebiao.h>
inherit F_CLEAN_UP;
#define MAX_ICONS 2159

int help();

int main(object me,string arg)
{
	int ico;
        string iicon="";
        string icon="";
        string iiicon="";
        iicon=(me->query("gender") == "����" )?"50001":"50002";
        if(!me->query("icon"))
        {
            iiicon=iicon;
            icon=HIR"���ͼ����ϵͳĬ�ϵ�: "+HIG+iicon+NOR;
        }
        else
        {
            iiicon=me->query("icon");
            icon="�㵱ǰ��ͼ����Ϊ "+HIG+iiicon+NOR;
        }
        
	if(arg)
	{
              if(sscanf(arg,"%d",ico)!=1 || ico < 1110 || ico >1246)
			return help();
		iiicon = "0" + ico;
                icon="�㵱ǰ��ͼ����Ϊ��0" + ico ;
		write("���ͼ���Ѿ����޸�Ϊ "+HIG+iiicon+NOR+" �ˣ�\n");
		me->set("icon",iiicon);
	}
	else help();
        
        tell_object(me,icon);
        tell_object(me,L_ICON(iiicon));
	return 1;
}

int help()
{
	write("�����ʽ��"+HIY+"icon [ͼ����]\n"+NOR+
		"    ������ñ������ѯ���޸��Լ���ͷ���š�\n"+
		"    Ŀǰͼ�����ѡ��Χ��"+HIR+" 50001 - 60000 "+NOR+" ��\n");
	return 1;
}


