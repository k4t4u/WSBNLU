import Navbar from './Navbar';
import Footer from './Footer';

export default function Layout({ children }) {
    return (
        <div className="flex flex-col min-h-screen bg-gray-50">
            <Navbar />
            <main className="container mx-auto flex-grow bg-white shadow-md rounded-lg my-8 p-6">
                {children}
            </main>
            <Footer />
        </div>
    );
}
