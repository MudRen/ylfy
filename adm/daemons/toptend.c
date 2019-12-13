//JackyBoy Write these Functions for CCTX's TOPTEN!
//Updated in 1999/3/8

#include <ansi.h>
#include <mudlib.h>

#define MAX_LEAVE_TOP 15

#define TOPTEN_JINGLI	"/topten/jingli.txt"
#define TOPTEN_DUSHU	"/topten/dushu.txt"
#define TOPTEN_RICH 	"/topten/rich.txt"
//#define TOPTEN_PKER	"/topten/pker.txt"
#define TOPTEN_EXP	    "/topten/exp.txt"
//#define TOPTEN_SHEN	"/topten/shen.txt"
#define TOPTEN_NEILI	"/topten/neili.txt"
//#define TOPTEN_PER	"/topten/per.txt"
//#define TOPTEN_AGE	"/topten/age.txt"
#define DUSHU_B 		NOR+WHT"����"HIR"����"NOR+WHT"���а�"NOR
#define JINGLI_B 		NOR+RED"����"HIW"����"NOR+RED"���а�"NOR
#define RICH_B 		    NOR+CYN"����"HIY"����"NOR+CYN"���а�"NOR
//#define PKER_B 		CYN"ʮ��"HIR"ɱ�˿�ħ"NOR
#define EXP_B           NOR+YEL"����"HIM"����"NOR+YEL"���а�"NOR
//#define SHEN_B        CYN"ʮ��"RED"а������"NOR       	
#define NEILI_B		    NOR+BLU"����"HIC"����"NOR+BLU"���а�"NOR
//#define PER_B		    CYN"����"HIM"ʮ����Ů"NOR
//#define AGE_B		    CYN"����ʮ��"GRN"��ǰ��"NOR

void topten_checkplayer(object);
int get_all_data(object,string);
int topten_del(string,string);
int topten_add(object,string);
int topten_save(string,string,string);
string topten_query(string);
string query_type();


void topten_checkplayer(object player)
{//������ò�����������컹�Ǻ����أ�������Щ����Ҫ�е����ֵģ�������Ů�Ա�
	topten_add(player,"rich");
	//topten_add(player,"pker");
	topten_add(player,"exp");
	//topten_add(player,"shen");
	topten_add(player,"neili");
	//topten_add(player,"per");	
	//topten_add(player,"age");
	topten_add(player,"jingli");
	topten_add(player,"dushu");
	return;
}

string query_type()
{
	return HIY+CHINESE_MUD_NAME+"�������������͵����а�\n"+
		HIR"һ��\t"NOR+RICH_B+"\n"+
		HIR"����\t"NOR EXP_B+"\n"+
		//HIR"����\t"NOR+PKER_B+"\n"+
		HIR"����\t"NOR+NEILI_B+"\n"+
		HIR"�ģ�\t"NOR+JINGLI_B+"\n"+
		HIR"�壺\t"NOR+DUSHU_B+"\n"+
		//HIR"�壺\t"NOR+SHEN_B+"\n"+
		//HIR"����\t"NOR+PER_B+"\n"+
		//HIR"�ߣ�\t"NOR+AGE_B+"\n"+
		NOR;
}
int topten_save(string f_name,string b_name,string str)
{
	string *astr;
	int i;

	astr=explode(str,"\n");

	str="";
	for(i=0;i<sizeof(astr)&&i<MAX_LEAVE_TOP;i++)//ԭ��10
		str+=astr[i]+"\n";

	if(!write_file(f_name,str,1))
		return notify_fail("�޷�д�ļ�"+f_name+"��Ȩ�޲���!���ܸ���"+b_name+"!\n");

	return 1;
}

string topten_query(string type)
{
	string b_name,f_name,str,*astr,*bstr,name,id;
	int i,j,data;
	switch(type)
	{
		case "rich":
			b_name=RICH_B;
			f_name=TOPTEN_RICH;
			break;
		/*case "pker":
			b_name=PKER_B;
			f_name=TOPTEN_PKER;
			break;*/
		case "exp":
			b_name=EXP_B;
			f_name=TOPTEN_EXP;
			break;
		/*case "shen":
			b_name=SHEN_B;
			f_name=TOPTEN_SHEN;
			break;*/
		case "neili":
			b_name=NEILI_B;
			f_name=TOPTEN_NEILI;
			break;
		case "jingli":
			b_name=JINGLI_B;
			f_name=TOPTEN_JINGLI;
			break;
		case "dushu":
			b_name=DUSHU_B;
			f_name=TOPTEN_DUSHU;
			break;
		default:
			return query_type();
	}
	if(file_size(f_name)==-1)
		return b_name+"�������ļ���û�д�����\n";
	astr=explode(read_file(f_name),"\n");
	str=HIG+CHINESE_MUD_NAME+" : "NOR+b_name+"\n";
	for(i=0;i<sizeof(astr);i++)
	{
		bstr=explode(astr[i],";");
		str+=NOR CYN"���е�"HIR+chinese_number(i+1)+NOR"��";
		for(j=0;j<sizeof(bstr);j++)
		{
			if(sscanf(bstr[j],"%s(%s)%d",name,id,data)!=3)
				return "���ݴ���!�ļ���"+f_name+"��"+i+"�е�"+j+"�\n"+
					"�������ݣ�"+bstr[j]+"\n";
			str+=name+"("+id+")\t";
		}
		str+="\n"NOR;
	}
	return str;
}
int get_all_data(object player,string type)
{
	int total;
	
	switch(type)
	{
		case "rich":
			total=((int)((player->query("more_money")*10000)+(player->query("money")/10000)));
			break;
		/*case "pker":
			total=(int)player->query("PKS");
			break;*/
		case "exp":
			total=(int)player->query("combat_exp") / LEVUP_EXP + player->query("xyzx_sys/level");
			break;
		case "dushu":
			total=(int)player->query_skill("literate",1);
			break;
		case "neili":
			total=(int)player->query("max_neili");
			break;
		case "jingli":
			total=(int)player->query("max_jingli");
			break;
		/*case "per":
			if (player->query("gender")!="Ů��")
			total=-1;
		else
			total=player->query_per();
			break;*/
		default:
			total=-1;//��-1��־���ͳ���
	}
	return total;
}

int topten_del(string pid,string type)
{
	string str,*astr,*bstr,b_name,f_name;
	int i,j,k;
	
	switch(type)
	{
		case "rich":
			b_name=RICH_B;
			f_name=TOPTEN_RICH;
			break;
		/*case "pker":
			b_name=PKER_B;
			f_name=TOPTEN_PKER;
			break;*/
		case "exp":
			b_name=EXP_B;
			f_name=TOPTEN_EXP;
			break;
		/*case "shen":
			b_name=SHEN_B;
			f_name=TOPTEN_SHEN;
			break;*/
		case "neili":
			b_name=NEILI_B;
			f_name=TOPTEN_NEILI;
			break;
		case "jingli":
			b_name=JINGLI_B;
			f_name=TOPTEN_JINGLI;
			break;
		case "dushu":
			b_name=DUSHU_B;
			f_name=TOPTEN_DUSHU;
			break;
		default:
			return notify_fail("û��"+type+"�������а�\n");
	}
	
	if(file_size(f_name)==-1)
		return notify_fail(b_name+"��û�д�����\n");
	
	str=read_file(f_name);
	
	astr=explode(str,"\n");
	for(i=0;i<sizeof(astr);i++)
	{
		//���а���id��Ϊ��
		if(strsrch(astr[i],pid)!=-1)
		{
			//Ϊ���ʾ����ֻ��һ��id����pid
			if(strsrch(astr[i],";")==-1)
			{
				str="";
				for(j=0;j<sizeof(astr);j++)
				{
					if(j!=i)
						str+=astr[j]+"\n";
				}
				return topten_save(f_name,b_name,str);
			}
			else
			{
				bstr=explode(astr[i],";");
				for(j=0;j<sizeof(bstr);j++)
				{
					//˵�����pid,Ӧ��ȥ��
					if(strsrch(bstr[j],pid)!=-1)
					{
						astr[i]="";
						for(k=0;k<sizeof(bstr);k++)
						{
							if(k!=j)
							{
								if((k+1)!=sizeof(bstr) && !((j+1)==sizeof(bstr) && j==(k+1)))
									astr[i]+=bstr[k]+";";
								else
									astr[i]+=bstr[k];
							}
						}
						//����ȥ����j��ѭ��Ӧ��ֹͣ,���ǲ�Ӱ����
					}
					str=implode(astr,"\n");
				}
				return topten_save(f_name,b_name,str);
			}
		}
	}
	return 1;
}

int topten_add(object player,string type)
{
	string str,name,id,b_name,f_name;
	string *astr;
	int i,j,data;
	
	//��ֹ��ʦ�μ����а�
	if(wizardp(player))
	return 0;
	
	switch(type)
	{
		case "rich":
			b_name=RICH_B;
			f_name=TOPTEN_RICH;
			break;
		/*case "pker":
			b_name=PKER_B;
			f_name=TOPTEN_PKER;
			break;*/
		case "exp":
			b_name=EXP_B;
			f_name=TOPTEN_EXP;
			break;
		/*case "shen":
			b_name=SHEN_B;
			f_name=TOPTEN_SHEN;
			break;*/
		case "neili":
			b_name=NEILI_B;
			f_name=TOPTEN_NEILI;
			break;
		case "jingli":
			b_name=JINGLI_B;
			f_name=TOPTEN_JINGLI;
			break;
		case "dushu":
			b_name=DUSHU_B;
			f_name=TOPTEN_DUSHU;
			break;
		default:
			return notify_fail("û��"+type+"�������а�\n");
	}
	
	if(!objectp(player) || !userp(player))
		return 0;
	
	if(file_size(f_name)==-1)
	{
		str=player->query("name")+"("+player->query("id")+")"+get_all_data(player,type);
		return topten_save(f_name,b_name,str);
	}

	//��Ҫ����
	if(get_all_data(player,type)==-1)
		return notify_fail("���ݲ�ѯ���󣬿����ǲ�ѯ���ʹ���\n");
	
	//Ӧ�����ų���player��id!
	topten_del(player->query("id"),type);
	str=read_file(f_name);
	astr=explode(str,"\n");
	i=0;
	
	while(i<sizeof(astr))
	{
		if(sscanf(astr[i],"%s(%s)%d",name,id,data)!=3) //|| sscanf(astr,"%s(%s)%d;%*s",name,id,data)!=3)
			return notify_fail(b_name+"�ļ����ݴ����������ʦ��\n");
		
		str="";
		
		if(data<(int)get_all_data(player,type))
		{
			//�������룬��ʱû������������ʮ�У�
			for(j=0;j<sizeof(astr);j++)
			{				
				if(strsrch(astr[j],player->query("id")) != -1 && strsrch(astr[j],player->query("name")) != -1)
					continue;

				if(j==i)
					str+=player->query("name")+"("+player->query("id")+")"+get_all_data(player,type)+"\n";
				str+=astr[j]+"\n";
			}
			return topten_save(f_name,b_name,str);
		}
		else
		if(data==(int)get_all_data(player,type))
		{
			//���ż���
			for(j=0;j<sizeof(astr);j++)
			{				
				if(strsrch(astr[j],player->query("id")) != -1 && strsrch(astr[j],player->query("name")) != -1)
					continue;
				
				if(j==i)
					str+=astr[j]+";"+player->query("name")+"("+player->query("id")+")"+get_all_data(player,type)+"\n";
				else
					str+=astr[j]+"\n";
			}
			return topten_save(f_name,b_name,str);
		}
		i++;
	}
	
	if(sizeof(astr)<MAX_LEAVE_TOP)//ԭ��10
	{
		str=implode(astr,"\n")+"\n"+player->query("name")+"("+player->query("id")+")"+get_all_data(player,type);
		return topten_save(f_name,b_name,str);
	}
	return 0;
}
