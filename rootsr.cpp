#include <Eigen/Eigen>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace Eigen;

int polysolver(int* coeff, VectorXcd* r, int n, MatrixXd* M){
  MatrixXd mat=*M;
  for(int i=0;i<n;i++)
    mat(i,n-1)=-coeff[i];
  *r=mat.eigenvalues();
  return 0;
}


int sz=10000;
char name_buf[30];
int count=0;
const int E[]={1,1,1};
const int m=2;

long pos(double x, double y){
  return (sz/2-(int)(y*sz/4))*sz+sz/2+(int)(x*sz/4); 
}

int main(){
  char* buf=(char*)malloc(sz*sz);
  for(int i=0;i<sz*sz;i++)buf[i]=0;
  double beta,x,y;
  //compute
  for(int n=2;n<28;n++){
    MatrixXd mat=MatrixXd::Zero(n,n);
    VectorXcd res=VectorXcd::Zero(n);
    for(int i=0;i<n-1;i++)
    mat(i+1,i)=1;
    long B=1;
    for(int i=0;i<n-1;i++)B*=(long)m;
    printf("n=%d\n",n);
    int w[n];
    int cor[n];
    int S[n];
    int w1[n];
    double rx[n];
    double ry[n];
    for(long i=0;i<B;i++){
      w[0]=m-1;S[0]=1;
      long N=i;
      for(int j=1;j<n;j++){
	w[j]=N%m;N=(N-N%m)/m;S[j]=S[j-1]*E[w[j-1]];
      }
      //for(int j=0;j<n;j++)
      //	printf("%d",w[j]);
      //printf("\n");
      
      // printf("here\n");
	//test Gora's condition
      if(S[n-1]*E[w[n-1]]!=1)continue;
      //    printf("here\n");

      int flag=0;
      for(int k=0;k<n-1;k++){  //    printf("here\n");

	  for(int j=0;j<n;j++)w1[j]=w[(j+k)%n];
	  for(int j=0;j<n;j++){      //printf("here\n");

	    if(S[j]*(w[j]-w1[j])>0)break;
	    else if(S[j]*(w[j]-w1[j])<0){flag=1;break;}
	  }
	  if(flag)break;
      }
      if(flag)continue;
      count++;
      // printf("heren\n");

      if(count%100000==0)printf("%d\n",count);
      for(int j=0;j<n;j++)
	cor[n-1-j]=-S[j]*(w[j]+(1-E[w[j]])/2);
      cor[0]-=1;
      //printf("herei\n");
      polysolver(cor, &res ,n,&mat);
      
      // printf("herej\n");
      for(int j=0;j<n;j++){
	//printf("%g,%g,%g\n",rx[j],ry[j],beta);
	buf[pos(res[j].real(),res[j].imag())]=1;
      }
    }
  }


  //output
    sprintf(name_buf,"out.pbm");
    printf("%s\n",name_buf);
    FILE* out=fopen(name_buf,"w");
    fprintf(out,"P1\n%d %d\n",sz,sz);
    for(long j=0;j<sz;j++)
      for(long k=0;k<sz;k++)
	{fputc('0'+buf[j*sz+k],out);
	  if(k==sz-1)fputc('\n',out);
	  else fputc(' ',out);
	}
    fclose(out);
  
  return 0;
}
